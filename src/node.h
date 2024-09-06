#pragma once

#include <raylib.h>
#include <raymath.h>

#define NODE_NEIGHBOUR_COUNT 4

typedef struct Node Node;

typedef struct Node {
    Vector2 position;
    Node *neighbours[NODE_NEIGHBOUR_COUNT];
} Node;

typedef struct NodeGroup {
    Node *nodes;
    int size;
} NodeGroup;

NodeGroup *NodeGroupCreate(void);
void NodeGroupDraw(NodeGroup *nodeGroup);
void NodeGroupFree(NodeGroup **nodeGroup);