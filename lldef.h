/*	lldef.h
 *	definitions for a LinkList package
 */

typedef struct LinkType
	{
	struct LinkType *next;
	struct LinkType *prev;
	char *item;
	} LinkType;

typedef struct LinkList
	{
	LinkType *head;
	LinkType *tail;
	LinkType *clp;

	int listLength;
	int itemLength;

	int (*match)();
	} LinkList;

void llSetMatch(LinkList *list, int (*newMatch)());
int llCheck(LinkList *list, const char *value);
void llSetSize(LinkList *list, int size);
void llInit(LinkList *list, const char *newItem);
void llHead(LinkList *list);
void llTail(LinkList *list);
int llNext(LinkList *list);
int llPrev(LinkList *list);
char *llRetrieve(LinkList *list, char *item);
void llAdd(LinkList *list, const char *newItem);
void llAddHead(LinkList *list, const char *newItem);
void llDelete(LinkList *list);
int llLength(LinkList *list);
