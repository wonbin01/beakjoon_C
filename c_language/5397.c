#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node *nodepointer;
typedef struct node 
{   
    char c;
    nodepointer rlink;
    nodepointer llink;
} Node;

void erase(nodepointer cursor);
void insert(nodepointer cursor, char key);
void freeNodes(Node *node);
char* processInput(char *sentence);

int main(void)
{
    int n;
    scanf("%d", &n);

    char **sentences = (char **)malloc(n * sizeof(char *));

    // Input
    for(int i = 0; i < n; i++)
    {
        sentences[i] = (char *)malloc(1000001 * sizeof(char));
        scanf("%s", sentences[i]);
    }

    // Processing
    char **results = (char **)malloc(n * sizeof(char *));
    for(int i = 0; i < n; i++)
    {
        results[i] = processInput(sentences[i]);
        free(sentences[i]);
    }
    free(sentences);

    // Output
    for(int i = 0; i < n; i++)
    {
        printf("%s\n", results[i]);
        free(results[i]);
    }
    free(results);

    return 0;
}

char* processInput(char *sentence)
{
    Node *keyword = (Node *)malloc(sizeof(Node));
    keyword->c = '\0';
    keyword->llink = NULL;
    keyword->rlink = NULL;
    nodepointer cursor = keyword;

    int m = strlen(sentence);
    for(int i = 0; i < m; i++)
    {
        if(sentence[i] == '<')
        {
            if(cursor->llink != NULL)
            {
                cursor = cursor->llink;
            }
        }
        else if(sentence[i] == '>')
        {
            if(cursor->rlink != NULL)
            {
                cursor = cursor->rlink;
            }
        }
        else if(sentence[i] == '-')
        {
            erase(cursor);
        }
        else
        {
            char key = sentence[i];
            insert(cursor, key);
        }
    }

    // Storing the output in a dynamically allocated array
    char *output = (char *)malloc(1000001 * sizeof(char));
    int j = 0;
    while(keyword->llink != NULL)
    {
        keyword = keyword->llink;
    }
    while(keyword != NULL)
    {
        output[j++] = keyword->c;
        keyword = keyword->rlink;
    }
    output[j] = '\0';

    // Freeing dynamically allocated memory
    freeNodes(keyword);

    return output;
}

void erase(nodepointer cursor)
{
    if(cursor->llink == NULL)
    {
        return;
    }
    else if(cursor->llink->llink == NULL)
    {
        nodepointer temp = cursor->llink;
        cursor->llink = NULL;
        free(temp);        
    }
    else if(cursor->rlink == NULL)
    {
        nodepointer temp = cursor->llink;
        temp->llink->rlink = cursor;
        cursor->llink = temp->llink;
        cursor->rlink = NULL;
        free(temp);
    }
    else
    {
        nodepointer temp=cursor->llink;
        temp->llink->rlink=cursor;
        cursor->llink=temp->llink;
        free(temp);
    }
}

void insert(nodepointer cursor, char key)
{
    Node *newnode = (Node *)malloc(sizeof(Node));
    newnode->c = key;

    if(cursor->llink == NULL)
    {
        newnode->llink = NULL;
        newnode->rlink = cursor;
        cursor->llink = newnode;
    }
    else
    {
        newnode->llink = cursor->llink;
        newnode->rlink = cursor;
        cursor->llink->rlink = newnode;
        cursor->llink = newnode;
    }
}

void freeNodes(Node *node)
{
    if (node == NULL)
        return;
    
    freeNodes(node->rlink);
    free(node);
}
