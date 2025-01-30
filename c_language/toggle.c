#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define IN 0
#define OUT 1
#define LOW 0
#define HIGH 1
#define BUFFER_MAX 3

#define BUTTON_PIN 20 
#define LED_PIN 17       
#define VALUE_MAX 40
#define DIRECTION_MAX 40

static int GPIOExport(int pin);
static int GPIOUnexport(int pin);
static int GPIODirection(int pin, int dir);
static int GPIORead(int pin);
static int GPIOWrite(int pin, int value);

int main(void) {
    int led_state = 0;
    int button_state, prev_button_state = 0;

    if (GPIOExport(LED_PIN) == -1 || GPIOExport(BUTTON_PIN) == -1) {
        return 1;
    }
    if (GPIODirection(LED_PIN, OUT) == -1 || GPIODirection(BUTTON_PIN, IN) == -1) {
        return 2;
    }

    while (1) {
        button_state = GPIORead(BUTTON_PIN);

        
        if (button_state == HIGH && prev_button_state == LOW) {
            led_state = !led_state;  
            if (GPIOWrite(LED_PIN, led_state) == -1) {
                return 3;
            }
            printf("LED State: %s\n", led_state ? "ON" : "OFF");
        }

        
        prev_button_state = button_state;

        
        usleep(100 * 1000);  
    }

    if (GPIOUnexport(LED_PIN) == -1 || GPIOUnexport(BUTTON_PIN) == -1) {
        return 4;
    }

    return 0;
}
static int GPIOExport(int pin) {
  char buffer[BUFFER_MAX];
  ssize_t bytes_written;
  int fd;

  fd = open("/sys/class/gpio/export", O_WRONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open export for writing!\n");
    return -1;
  }

  bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
  write(fd, buffer, bytes_written);
  close(fd);
  return 0;
}

static int GPIOUnexport(int pin) {
  char buffer[BUFFER_MAX];
  ssize_t bytes_written;
  int fd;

  fd = open("/sys/class/gpio/unexport", O_WRONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open unexport for writing!\n");
    return -1;
  }

  bytes_written = snprintf(buffer, BUFFER_MAX, "%d", pin);
  write(fd, buffer, bytes_written);
  close(fd);
  return 0;
}
static int GPIODirection(int pin, int dir) {
  static const char s_directions_str[] = "in\0out";

  char path[DIRECTION_MAX];
  int fd;

  snprintf(path, DIRECTION_MAX, "/sys/class/gpio/gpio%d/direction", pin);
  fd = open(path, O_WRONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open gpio direction for writing!\n");
    return -1;
  }

  if (write(fd, &s_directions_str[IN == dir ? 0 : 3], IN == dir ? 2 : 3) == -1) {
    fprintf(stderr, "Failed to set direction!\n");
    close(fd);  
    return -1;
  }

  close(fd);
  return 0;
}
static int GPIORead(int pin) {
  char path[VALUE_MAX];
  char value_str[3];
  int fd;

  snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
  fd = open(path, O_RDONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open gpio value for reading!\n");
    return -1;
  }

  if (read(fd, value_str, 3) == -1) {
    fprintf(stderr, "Failed to read value!\n");
    close(fd);  
    return -1;
  }

  close(fd);
  return atoi(value_str);
}
static int GPIOWrite(int pin, int value) {
  static const char s_values_str[] = "01";

  char path[VALUE_MAX];
  int fd;

  snprintf(path, VALUE_MAX, "/sys/class/gpio/gpio%d/value", pin);
  fd = open(path, O_WRONLY);
  if (fd == -1) {
    fprintf(stderr, "Failed to open gpio value for writing!\n");
    return -1;
  }

  if (write(fd, &s_values_str[LOW == value ? 0 : 1], 1) != 1) {
    fprintf(stderr, "Failed to write value!\n");
    close(fd);  
    return -1;
  }

  close(fd);
  return 0;
}
