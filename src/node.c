#include "node.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

typedef enum NodeNeighbourSide {
    NODE_LEFT,
    NODE_RIGHT,
    NODE_UP,
    NODE_DOWN,
} NodeNeighbourSide;

void NodeDraw(Node *node) {
    assert(node != NULL);

    for (int i = 0; i < NODE_NEIGHBOUR_COUNT; ++i) {
        if (node->neighbours[i] == NULL) {
            continue;
        }

        DrawLineV(node->position, node->neighbours[i]->position, BLACK);
    }

    DrawCircleV(node->position, 4.0f, RED);
}

void NodeSetNeighbour(Node *node, Node *neighbour, NodeNeighbourSide side) {
    node->neighbours[side] = neighbour;

    NodeNeighbourSide neighbourSide;
    switch (side)
    {
    case NODE_LEFT:
        neighbourSide = NODE_RIGHT;
        break;
    
    case NODE_RIGHT:
        neighbourSide = NODE_LEFT;
        break;

    case NODE_UP:
        neighbourSide = NODE_DOWN;
        break;
    
    case NODE_DOWN:
        neighbourSide = NODE_UP;
        break;
    
    default:
        break;
    }

    neighbour->neighbours[neighbourSide] = node;
}

NodeGroup *NodeGroupCreate(void) {
    NodeGroup *nodeGroup = (NodeGroup *)malloc(sizeof(NodeGroup));
    if (nodeGroup == NULL) {
        fprintf(stderr, "Failed to allocate NodeGroup object!\n");
        exit(EXIT_FAILURE);
    }

    nodeGroup->size = 7;
    nodeGroup->nodes = (Node *)malloc(sizeof(Node) * nodeGroup->size);

    nodeGroup->nodes[0] = (Node){ 0 };
    nodeGroup->nodes[0].position = (Vector2){ 32.0f, 32.0f };

    nodeGroup->nodes[1] = (Node){ 0 };
    nodeGroup->nodes[1].position = (Vector2){ 128.0f, 32.0f };
    NodeSetNeighbour(&nodeGroup->nodes[0], &nodeGroup->nodes[1], NODE_RIGHT);

    nodeGroup->nodes[2] = (Node){ 0 };
    nodeGroup->nodes[2].position = (Vector2){ 32.0f, 64.0f };

    nodeGroup->nodes[3] = (Node){ 0 };
    nodeGroup->nodes[3].position = (Vector2){ 128.0f, 64.0f };

    nodeGroup->nodes[4] = (Node){ 0 };
    nodeGroup->nodes[4].position = (Vector2){ 160.0f, 64.0f };

    nodeGroup->nodes[5] = (Node){ 0 };
    nodeGroup->nodes[5].position = (Vector2){ 32.0f, 160.0f };

    nodeGroup->nodes[6] = (Node){ 0 };
    nodeGroup->nodes[6].position = (Vector2){ 160.0f, 160.0f };

    return nodeGroup;
}

void NodeGroupDraw(NodeGroup *nodeGroup) {
    assert(nodeGroup != NULL);

    for (int i = 0; i < nodeGroup->size; ++i) {
        NodeDraw(&nodeGroup->nodes[i]);
    }
}

void NodeGroupFree(NodeGroup **nodeGroup) {
    free((*nodeGroup)->nodes);
    free(*nodeGroup);
    *nodeGroup = NULL;
}