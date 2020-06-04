//RECURSIVE INSERTION SORT FOR LINKED LISTS
node* sort(node*head)
{
	if(head->next == NULL)
			return head;
	node* rest = sort(head->next);
	node* result = rest;
	int data = head->data;
	bool flag = false;

	node* prev = head;
	while(rest != NULL and data>rest->data)
	{
		prev = rest;
		rest = rest->next;
		flag = true;

	}
	if(flag)
	{
		prev->next = new node(data);
		prev->next->next = rest;
		return result;
	}
	else
	{
		head->next = result;
		return head;
	}	
}

// INSERTION SORT FOR LINKED LISTS

