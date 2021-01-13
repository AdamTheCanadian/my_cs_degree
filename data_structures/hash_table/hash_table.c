#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct HashItem {
  char* key;
  char* value;
};

struct HashTable {
  int size;
  int count;
  int size_index;
  struct HashItem** items;
};

/* Insert a new key/value into the hash table */
void insert(struct HashTable* ht, char* newKey, char* newValue);

/* Find element in the hash table */
char* search_hash_table(struct HashTable* ht, char* k);

struct HashItem* new_item(char* newKey, char* newValue);

/* Hash function based off the new key, size of the hash table, and our attempt number.
  Attempt used to avoid collision */
int hash(char* key, int size, int attempt);

int generic_hash(char* s, int a, int m);


int main() {
  struct HashTable hash_table;
  /* Allocate space for the hash table */
  hash_table.size = 50;
  hash_table.count = 0;
  hash_table.items = calloc((size_t)hash_table.size, sizeof(struct HashItem*));

  char* k = "apple";
  char* v = "apple_value";
  insert(&hash_table, k, v);

  printf("Searched has for key %s and found value %s\n", k, search_hash_table(&hash_table, k));
  return 0;
}

void insert(struct HashTable* ht, char* newKey, char* newValue) {
  /* Calculate the load factor of the table */
  double load = (double)ht->count * 100.0 / (double)ht->size;
  if (load > 70.0) {
    // resize
  }
  // TODO: What if key already exists
  struct HashItem* item = new_item(newKey, newValue);
  /* Create the hash index for this key, based on the size of the hash table, 
    and our attempt number. Will keep increasing attempt until we find an index
    with no collisions */
  int hash_index = hash(item->key, ht->size, 0);
  
  /* Check for collision */
  struct HashItem* existing_item = ht->items[hash_index];
  int i = 1;
  while (existing_item != NULL) {
    /* Try and find a new index */
    hash_index = hash(item->key, ht->size, 0);
    existing_item = ht->items[hash_index];
    i += 1;
  }
  printf("Inserted key '%s' with a hash index of %d on attempt %d\n", newKey, hash_index, i);
  ht->items[hash_index] = item;
  ht->count += 1;
}

struct HashItem* new_item(char* newKey, char* newValue) {
  /* Allocate memory for a a new hashtable item */
  struct HashItem* item = malloc(sizeof(struct HashItem));
  /* Copy the key/value */
  item->key = malloc(strlen(newKey) + 1);
  strcpy(item->key, newKey);
  item->value = malloc(strlen(newValue) + 1);
  strcpy(item->value, newValue);
  return item;
}

int hash(char* key, int size, int attempt) {
  int a = generic_hash(key, 151, size);
  int b = generic_hash(key, 163, size);
  return (a + (attempt * (b + 1))) % size;
}

int generic_hash(char* s, int a, int m) {
  long hash = 0;
  const int len_s = strlen(s);
  for (int i = 0; i < len_s; i++) {
    hash += (long)pow(a, (len_s - (i + 1))) * s[i];
    /* Make sure the hash value does not exceed m by taking the remainder */
    hash = hash % m;
  }
  return (int)hash;
}

char* search_hash_table(struct HashTable* ht, char* k) {
  int index = hash(k, ht->size, 0);
  struct HashItem* item = ht->items[index];
  int i = 0;
  while (item != NULL) {
    if (strcmp(item->key, k) == 0) {
      return item->value;
    }
    int index = hash(k, ht->size, i);
    item = ht->items[index];
    i += 1;
  }
  return NULL;
}