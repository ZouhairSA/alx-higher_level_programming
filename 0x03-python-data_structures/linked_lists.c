#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t print_listint(const listint_t *h)
{
const listint_t *current;
unsigned int n;
current = h;
n = 0;
while (current != NULL)
{
printf("%i\n", current->n);
current = current->next;
n++;
}
return (n);
}
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new;
listint_t *current;
current = *head;
new = malloc(sizeof(listint_t));
if (new == NULL)
return (NULL);
new->n = n;
new->next = NULL;
if (*head == NULL)
*head = new;
else
{
while (current->next != NULL)
current = current->next;
current->next = new;
}
return (new);
}
void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

listint_t *reverse_list(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
	current = next;
}
*head = prev;
return *head;
}

