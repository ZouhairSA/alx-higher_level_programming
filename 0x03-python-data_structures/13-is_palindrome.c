#include "lists.h"

int is_palindrome(listint_t **head)
{
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *half_reversed = NULL;

    if (*head == NULL || (*head)->next == NULL)
        return (1);

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    half_reversed = reverse_list(&slow);

    while (half_reversed != NULL)
    {
        if ((*head)->n != half_reversed->n)
            return (0);

        *head = (*head)->next;
        half_reversed = half_reversed->next;
    }

    return (1);
}

