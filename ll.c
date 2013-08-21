/*	ll.c
 *	implementation of a LinkList package
 */

#include <lldef.h>
#include <stdlib.h>
#include <string.h>

#define moveitem(A, B) memmove(B,A,list->itemLength)

void llSetMatch(LinkList *list, int (*newMatch)())
	{
	list->match = newMatch;
	}

int llCheck(LinkList *list, const char *value)
	{
	for(;;)
		{
		if((*list->match)(list->clp->item, value))
			return(1);
		else
			if (!llNext(list))
				return(0);
		}
	return(0);
	}


void llSetSize(LinkList *list, int size)
	{
	list->itemLength = size;
	}


static LinkType *llCreateLink(LinkList *list)
	{
	LinkType *link = (LinkType *)malloc(sizeof(LinkType));
	link->item = malloc(list->itemLength);
	return(link);
	}


void llInit(LinkList *list, const char *newItem)
	{
	list->head = list->tail = list->clp = llCreateLink(list);
	list->clp->next = list->clp->prev = NULL;
	moveitem(newItem, list->clp->item);
	list->listLength = 1;
	}


void llHead(LinkList *list)
	{
	list->clp = list->head;
	}


void llTail(LinkList *list)
	{
	list->clp = list->tail;
	}


int llNext(LinkList *list)
	{
	if(list->clp->next == NULL)
		{
		return(0);
		}
	else
		{
		list->clp = list->clp->next;
		return(1);
		}
	return(0);
	}


int llPrev(LinkList *list)
	{
	if(list->clp->prev == NULL)
		{
		return(0);
		}
	else
		{
		list->clp = list->clp->prev;
		return(1);
		}
	return(0);
	}


char *llRetrieve(LinkList *list, char *item)
	{
	moveitem(list->clp->item, item);
	return(item);
	}


void llAdd(LinkList *list, const char *newItem)
	{
	LinkType *newLink = llCreateLink(list);

	moveitem(newItem, newLink->item);
	list->listLength++;

	newLink->next = list->clp->next;
	newLink->prev = list->clp;
	if(list->tail == list->clp)
		list->tail = newLink;
	else
		list->clp->next->prev = newLink;
	
	list->clp->next = newLink;
	list->clp = newLink;
	}


void llAddHead(LinkList *list, const char *newItem)
	{
	LinkType *newLink = NULL;

	if(llLength(list) == 0)
		{
		llInit(list, newItem);
		return;
		}
	
	newLink = llCreateLink(list);
	moveitem(newItem, newLink->item);
	list->listLength++;

	newLink->prev = NULL;
	newLink->next = list->head;
	list->head->prev = newLink;
	list->clp = list->head = newLink;
	}


void llDelete(LinkList *list)
	{
	LinkType *before;
	LinkType *after;

	if(list->head == list->clp && list->tail == list->clp)
		{
		list->head = list->tail = NULL;
		}
	else if(list->head == list->clp)
		{
		list->head = list->head->next;
		list->head->prev = NULL;
		}
	else if(list->tail == list->clp)
		{
		list->tail = list->tail->prev;
		list->tail->next = NULL;
		}
	else
		{
		before = list->clp->prev;
		after = list->clp->next;

		before->next = after;
		after->prev = before;
		}
	
	free(list->clp->item);
	list->clp = list->head;
	list->listLength--;
	}


int llLength(LinkList *list)
	{
	return(list->listLength);
	}
