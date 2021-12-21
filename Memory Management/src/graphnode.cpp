#include "graphedge.h"
#include "graphnode.h"
#include <iostream>
#include <memory>

GraphNode::GraphNode(int id)
{
     //std::cout << "Graph node created" << std::endl;
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    //std::cout << "ChatBot Destructor in Graphnode" << std::endl;
    //delete _chatBot; 

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

//void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
void GraphNode::AddEdgeToParentNode(std::unique_ptr<GraphEdge>& edge)
{
    _parentEdges.push_back(edge.get());
}

//void GraphNode::AddEdgeToChildNode(GraphEdge *edge)
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
//void GraphNode::MoveChatbotHere(ChatBot *chatbot)
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    //_chatBot->SetCurrentNode(this);
    _chatBot.SetCurrentNode(this);
}    

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
//void GraphNode::MoveChatbotToNewNode(std::unique_ptr<GraphNode> newNode)
{
    //newNode->MoveChatbotHere(_chatBot);
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
//std::unique_ptr<GraphEdge> GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}