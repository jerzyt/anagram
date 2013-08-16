#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <lldef.h>

#define MAX_LEN 80

#define MAX_ENTRIES 65521
#define HASH_RESOLVER 41

/*	compile/link command:
	gcc -I. -O2 -o anagram.gcc anagram.c ll.c
*/

typedef struct KeyList
	{
	char *key;
	LinkList list;
	int count;
	} KeyList;

static KeyList kl[MAX_ENTRIES];
static int collisionCount;

int charComp(const void *p1, const void *p2)
	{
	return((int)(*(const char *)p1 - *(const char *)p2));
	}

void hash_insert(unsigned int hashVal, const char *key, const char *word)
	{
	if(kl[hashVal].key == NULL)
		{
		kl[hashVal].key = strdup(key);
		kl[hashVal].count++;
		llSetSize(&kl[hashVal].list, sizeof(char *));
		llInit(&kl[hashVal].list, (char *)&word);
		}
	else if(strcmp(kl[hashVal].key, key) == 0)
		{
		kl[hashVal].count++;
		llAdd(&kl[hashVal].list, (char *)&word);
		}
	else	/* collision */
		{
		hashVal += HASH_RESOLVER;
		hashVal %= MAX_ENTRIES;
		hash_insert(hashVal, key, word);

		++collisionCount;
		}
	}

static unsigned int hash(const char *str)
	{
	unsigned int h = 0;
	unsigned int g = 0;

	while(*str)
		{
		h = (h << 4) + *str++;
		if(g = (h & 0xF0000000))
			h ^= g >> 24;
		h &= ~g;
		}

	return(h);
	}

int main()
	{
	char *dictFile = "words";
	FILE *inFile = NULL;
	int recNum = 0;
	int i;
	char *lptr = NULL;
	char line[MAX_LEN];

	if((inFile = fopen(dictFile, "r")) == NULL)
		{
		printf("Can't open %s\n", dictFile);
		exit(1);
		}
	
	while((lptr = fgets(line, MAX_LEN, inFile)) != NULL)
		{
		int len = strlen(line);
		char *sortedWord = NULL;
		unsigned int hashVal = 0;

		++recNum;

		line[--len] = '\0';		/* strip EOL */
		sortedWord = strdup(line);
		qsort(sortedWord, len, 1, charComp);
		hashVal = hash(sortedWord) % MAX_ENTRIES;
		/* printf("%-10u %s\n", hashVal, sortedWord); */

		hash_insert(hashVal, sortedWord, strdup(line));
		free(sortedWord);
		}
	
	fclose(inFile);

	for(i = 0; i < MAX_ENTRIES; ++i)
		{
		if(kl[i].count > 3)
			{
			char word[4];

			/* printf("%5u, %d, %s\n", i, kl[i].count, kl[i].key); */
			printf("%s\t=>\t", kl[i].key);
			while(llLength(&kl[i].list))
				{
				llRetrieve(&kl[i].list, word);
				printf(" %s", *(char **)word);
				llDelete(&kl[i].list);
				}
			printf("\n");
			}
		}

	printf("Detected %d collisions\n", collisionCount);
	return(0);
	}
