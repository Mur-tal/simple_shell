#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include "shell.h"
#include "node.h"
#include "parser.h"

/**
 * new_node - function to create new node
 * @type: type of node
 *
 * Return: success
 */

struct node_s *new_node(enum node_type_e type)
{
	struct node_s *node = malloc(sizeof(struct node_s));

	if (!node)
	{
		return (NULL);
	}

	memset(node, 0, sizeof(struct node_s));
	node->type = type;

	return (node);
}

/**
 * add_child_node - function to create a child node
 * @parent: parent node
 * @child: the child node
 *
 * Return: success
 */

void add_child_node(struct node_s *parent, struct node_s *child)
{
	if (!parent || !child)
	{
		return;
	}

	if (!parent->first_child)
	{
	parent->first_child = child;
	}
	else
	{
		struct node_s *sibling = parent->first_child;

		while (sibling->next_sibling)
		{
			sibling = sibling->next_sibling;
		}

		sibling->next_sibling = child;
		child->prev_sibling = sibling;
	}
	parent->children++;
}

/**
 * set_node_val_str - function to set value of nodes
 * @node: node to set
 * @val: the node value
 *
 * Return: success
 */

void set_node_val_str(struct node_s *node, char *val)
{
	node->val_type_e = VAL_STR;       /* added _e to make it val_type_e */

	if (!val)
	{
		node->val.str = NULL;
	}
	else
	{
		char *val2 = malloc(strlen(val) + 1);

		if (!val2)
		{
			node->val.str = NULL;
		}
		else
		{
			strcpy(val2, val);
			node->val.str = val2;
		}
	}
}

/**
 * free_node_tree - fnct to free node
 * @node: node to be freed
 *
 * Return: success
 */

void free_node_tree(struct node_s *node)
{
	if (!node)
	{
		return;
	}

	struct node_s *child = node->first_child;

	while (child)
	{
		struct node_s *next = child->next_sibling;

		free_node_tree(child);
		child = next;
	}

	if (node->val_type_e == VAL_STR)     /* added _e to make it val_type_e */
	{
		if (node->val.str)
		{
			free(node->val.str);
		}
	}
	free(node);
}
