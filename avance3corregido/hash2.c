#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define NR_BUCKETS 1024

struct StrHashNode {
    char *key;
    void *value;
    int type;
    int direction;
    struct StrHashNode *next;
};

struct StrHashTable {
    struct StrHashNode *buckets[NR_BUCKETS];
    void (*free_key)(char *);
    void (*free_value)(void*);
    unsigned int (*hash)(const char *key);
    int (*cmp)(const char *first,const char *second);
};


struct StrHashTableProc {
    struct StrHashNodeProc *buckets[NR_BUCKETS];
    void (*free_key)(char *);
    void (*free_value)(void*);
    unsigned int (*hash)(const char *key);
    int (*cmp)(const char *first,const char *second);
};

struct StrHashNodeProc {
    char *key;
    void *value;
    struct StrHashTable *vartable;
    struct StrHashTable *partable;
    struct StrHashNodeProc *next;
    int numberParameters; 
    int numberLocalVars; 
    int cuadruploInicial;
};


void *get(struct StrHashTable *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNode *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->value;
        node = node->value;
    }
    return NULL;
}

int getProc(struct StrHashTableProc *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return 1;
        node = node->value;
    }
    return 0;
}

int getType(struct StrHashTable *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNode *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->type;
        return node->type;
    } 
}

int getDirection(struct StrHashTable *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNode *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->direction;
        return node->direction;
    } 
	return -1;
}

int getNumberLocalVars(struct StrHashTableProc *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->numberLocalVars;
        return node->numberLocalVars;
    } 
	return -1;
}


void setNumberParameters(struct StrHashTableProc *table,const char *key, int numberParameters){

    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            {}
        node->numberParameters = numberParameters;
	return ;
    }
	return ;

}

void setNumberLocalVars(struct StrHashTableProc *table,const char *key, int numberLocalVars){

    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            { }
        node->numberLocalVars = numberLocalVars;
	return ;
    }
	return ;
}

void setCuadruploInicial(struct StrHashTableProc *table,const char *key, int cuadruploInicial){

    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            {}
        node->cuadruploInicial = cuadruploInicial;
	return;
    }
	return ;
}

struct StrHashTable *getPointerTbl(struct StrHashTableProc *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->vartable;
        return node->vartable;
    } 
}

struct StrHashTable *getPointerParTbl(struct StrHashTableProc *table,const char *key)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc *node;
    node = table->buckets[bucket];
    while(node) {
        if(table->cmp(key,node->key) == 0)
            return node->partable;
        return node->partable;
    } 
}



int insert(struct StrHashTable *table, char *key,void *value, int type, int direction)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNode **tmp;
    struct StrHashNode *node ;
 
    tmp = &table->buckets[bucket];

    while(*tmp) {
        if(table->cmp(key,(*tmp)->key) == 0)
            break;
        tmp = &(*tmp)->next;
    }
    if(*tmp) {
        if(table->free_key != NULL)
            table->free_key((*tmp)->key);
        if(table->free_value != NULL)
            table->free_value((*tmp)->value);
        node = *tmp;
    } else {
        node = malloc(sizeof *node);
        if(node == NULL)
            return -1;
        node->next = NULL;
        *tmp = node;
    }
	
	if(node->key != NULL) {
		printf("ID Repetida: \n");
		return -1;
	}
	else
	{
   		node->key = key;
    		node->value = value;
		node->type=type;
		node->direction=direction;

		printf("%s\t%i\t%i\n", node->key , node->type ,node->direction  );
	}
    return 0;
}

unsigned int foo_strhash(const char *str)
{
    unsigned int hash = 0;
    for(; *str; str++)
        hash = 31*hash + *str;
    return hash;
}


int insertProc(struct StrHashTableProc *table, struct StrHashTable *vartable, struct StrHashTable *partable, char *key,void *value, int numberParameters, int numberLocalVars, int cuadruploInicial)
{
    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc **tmp;
    struct StrHashNodeProc *node ;
    tmp = &table->buckets[bucket];

    while(*tmp) {
        if(table->cmp(key,(*tmp)->key) == 0)
            break;
        tmp = &(*tmp)->next;
    }
    if(*tmp) {
        if(table->free_key != NULL)
            table->free_key((*tmp)->key);
        if(table->free_value != NULL)
            table->free_value((*tmp)->value);
        node = *tmp;
    } else {
        node = malloc(sizeof *node);
        if(node == NULL)
            return -1;
        node->next = NULL;
        *tmp = node;
    }
	
	if(node->key != NULL) {
		printf("ID Proc Repetida: %s\n", key);
	}
	else
	{
		printf("=======================PROC ");
   		node->key = key;
    		node->value = value;
		node->vartable = vartable;
		node->partable = partable;
		node->numberParameters = numberParameters;
		node->numberLocalVars = numberLocalVars;
		node->cuadruploInicial = cuadruploInicial;
		//struct StrHashTable tblee = {{0},NULL,NULL,foo_strhash,strcmp};
		//node->vartable[0] = value; 
	}
    return 0;
}





struct StrHashNodeProc getProcNode(struct StrHashTableProc *table,char *key,void *value){

    unsigned int bucket = table->hash(key)%NR_BUCKETS;
    struct StrHashNodeProc **tmp;
    struct StrHashNodeProc *node ;
    tmp = &table->buckets[bucket];

    while(*tmp) {
        if(table->cmp(key,(*tmp)->key) == 0)
            break;
        tmp = &(*tmp)->next;
    }
    if(*tmp) {
        if(table->free_key != NULL)
            table->free_key((*tmp)->key);
        if(table->free_value != NULL)
            table->free_value((*tmp)->value);
        node = *tmp;
    } else {
        node = malloc(sizeof *node);
       // if(node == NULL)
       //     return -1;
        node->next = NULL;
        *tmp = node;
    }
return *node;

}



/*
int main(int argc,char *argv[])
{

    struct StrHashTable tbl = {{0},NULL,NULL,foo_strhash,strcmp};
    struct StrHashTableProc tblProc = {{0},NULL,NULL,foo_strhash,strcmp};

    insertProc(&tblProc,&tbl,"programa","programa");
    insert(&tbl,"Test","TestValue",1,1000);
    puts(get(getPointerTbl(&tblProc,"programa"),"Test"));    


    insert(&tbl,"Test","TestValue",1,1000);
    insert(&tbl,"Test2","TestValue2",2,2000);
    puts(get(&tbl,"Test"));
    insert(&tbl,"Test","TestValueReplaced",3,2010);
    puts(get(&tbl,"Test"));
    printf("Tipo: %i\n",getType(&tbl,"Testtt"));


    return 0;
}
*/

