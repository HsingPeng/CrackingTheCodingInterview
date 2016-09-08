#include <stdio.h>
#include <stdlib.h>

struct Cat {
	int num;
	int time;
	struct Cat *next;
};

struct Dog {
	int num;
	int time;
	struct Dog *next;
};

struct CatList {
	struct Cat *first;
	struct Cat *last;
};

struct DogList {
	struct Dog *first;
	struct Dog *last;
};

struct AnimalList {
	struct CatList catList;
	struct DogList dogList;
	int time;
};

inline int enqueueCat(struct CatList *list, struct Cat *cat)
{
	if (list->last == NULL) {
		list->last = cat;
		list->first = cat;
	} else {
		list->last->next = cat;
		list->last = cat;
	}
	
	return 0;
}

inline int enqueueDog(struct DogList *list, struct Dog *dog)
{
	if (list->last == NULL) {
		list->last = dog;
		list->first = dog;
	} else {
		list->last->next = dog;
		list->last = dog;
	}

	return 0;
}

int enqueue(char type, void *animal, struct AnimalList *animalList)
{
	switch (type) {
		case 'd':
			enqueueDog(&animalList->dogList, animal);
			break;
		case 'c':
			enqueueCat(&animalList->catList, animal);
			break;
	}

	return 0;
}

struct Dog *dequeueDog(struct DogList *dogList)
{
	struct Dog *dog = dogList->first;

	if (dog == NULL) {
		fprintf(stderr, "No dogs left.\n");
		return NULL;
	}

	dogList->first = dog->next;

	if (dogList->first == NULL) {
		dogList->last = NULL;
	}
	
	printf("dequeueDog: dog num = %d\n", dog->num);

	return dog;
}

struct Cat *dequeueCat(struct CatList *catList)
{
	struct Cat *cat = catList->first;

	if (cat == NULL) {
		fprintf(stderr, "No cats left.\n");
		return NULL;
	}

	catList->first = cat->next;

	if (catList->first == NULL) {
		catList->last = NULL;
	}

	printf("dequeueCat: cat num = %d\n", cat->num);

	return cat;
}

int dequeueAny(struct AnimalList *animalList, void *animal)
{
	struct DogList *dogList = &animalList->dogList;
	struct CatList *catList = &animalList->catList;

	if (dogList->first == NULL && catList->first == NULL) {
		return 0;
	} else if (catList->first == NULL || dogList->first->time < catList->first->time) {
		animal = dequeueDog(dogList);
		return 'd';
	} else {
		animal = dequeueCat(catList);
		return 'c';
	}
}

struct Cat *createCat(struct AnimalList *animalList, int num)
{
	struct Cat *cat = (struct Cat *)malloc(sizeof(struct Cat));
	if (cat == NULL) {
		fprintf(stderr, "create cat error.\n");
		return NULL;
	}
	
	cat->num = num;
	cat->time = animalList->time++;
	cat->next = NULL;

	return cat;
}

struct Dog *createDog(struct AnimalList *animalList, int num)
{
	struct Dog *dog = (struct Dog *)malloc(sizeof(struct Dog));
	if (dog == NULL) {
		fprintf(stderr, "create dog error.\n");
		return NULL;
	}
	
	dog->num = num;
	dog->time = animalList->time++;
	dog->next = NULL;

	return dog;
}


int main()
{
	struct AnimalList animalList;
	animalList.catList.first = NULL;
	animalList.catList.last = NULL;
	animalList.dogList.first = NULL;
	animalList.dogList.last = NULL;
	animalList.time = 0;


	enqueue('c', createCat(&animalList, 111), &animalList);
	enqueue('c', createCat(&animalList, 112), &animalList);
	enqueue('d', createDog(&animalList, 101), &animalList);
	enqueue('c', createCat(&animalList, 113), &animalList);
	enqueue('c', createCat(&animalList, 114), &animalList);
	enqueue('d', createDog(&animalList, 102), &animalList);
	enqueue('d', createDog(&animalList, 103), &animalList);

	void *animal = NULL;
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);
	dequeueAny(&animalList, animal);

	return 0;
}
