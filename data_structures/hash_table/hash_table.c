#include <string.h>
#include <stdlib.h>

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

struct HashItem* new_item(char* newKey, char* newValue);

int main() {
  struct HashTable hash_table;

}

void insert(struct HashTable* ht, char* newKey, char* newValue) {
  /* Calculate the load factor of the table */
  double load = (double)ht->count * 100.0 / (double)ht->size;
  if (load > 70.0) {
    // resize
  }
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