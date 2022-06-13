#include <iostream>
struct list
{
	int field; // ïîëå äàííûõ
	struct list* next; // óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
	struct list* prev; // óêàçàòåëü íà ïðåäûäóùèé ýëåìåíò
};

struct list* INIT(int a)  // à- çíà÷åíèå ïåðâîãî óçëà
{
	struct list* list;
	// âûäåëåíèå ïàìÿòè ïîä êîðåíü ñïèñêà
	list = (struct list*)malloc(sizeof(struct list));
	list->field = a;
	list->next = list; // óêàçàòåëü íà ñëåäóþùèé óçåë
	list->prev = list; // óêàçàòåëü íà ïðåäûäóùèé óçåë
	return(list);
}

struct list* ADD(list* list, int number)
{
	struct list* temp, *p;
	temp = (struct list*)malloc(sizeof(list));

	p = list->next; // ñîõðàíåíèå óêàçàòåëÿ íà ñëåäóþùèé óçåë
	list->next = temp; // ïðåäûäóùèé óçåë óêàçûâàåò íà ñîçäàâàåìûé

	temp->field = number; // ñîõðàíåíèå ïîëÿ äàííûõ äîáàâëÿåìîãî óçëà

	temp->next = p; // ñîçäàííûé óçåë óêàçûâàåò íà ñëåäóþùèé óçåë
	temp->prev = list; // ñîçäàííûé óçåë óêàçûâàåò íà ïðåäûäóùèé óçåë
	p->prev = temp;
	return(temp);
}

struct list* DELETE(list* list)
{
	struct list* prev, *next;
	prev = list->prev; // óçåë, ïðåäøåñòâóþùèé lst
	next = list->next; // óçåë, ñëåäóþùèé çà lst
	prev->next = list->next; // ïåðåñòàâëÿåì óêàçàòåëü
	next->prev = list->prev; // ïåðåñòàâëÿåì óêàçàòåëü
	free(list); // îñâîáîæäàåì ïàìÿòü óäàëÿåìîãî ýëåìåíòà
	return(prev);
}

void PRINT(list* list)
{
	struct list* p;
	p = list;
	do {
		printf("%d ", p->field); // âûâîä çíà÷åíèÿ ýëåìåíòà p
		p = p->next; // ïåðåõîä ê ñëåäóþùåìó óçëó
	} while (p != list); // óñëîâèå îêîí÷àíèÿ îáõîäà
}

void PRINTR(list* list)
{
	struct list* p;
	p = list;
	do {
		p = p->prev;  // ïåðåõîä ê ïðåäûäóùåìó óçëó
		printf("%d ", p->field); // âûâîä çíà÷åíèÿ ýëåìåíòà p
	} while (p != list); // óñëîâèå îêîí÷àíèÿ îáõîäà
}

int main()
{
	list* list = INIT(10);
	ADD(list, 15);
	ADD(list, 1);
	ADD(list, 3);
	PRINT(list);
	DELETE(list);
	return 0;
}