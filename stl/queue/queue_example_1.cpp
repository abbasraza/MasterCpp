//
//  queue_example_1.cpp
//  A simple example of using std::queue to enqueue and dequeue messages
//
//  Created by Abbas on 10/12/2021.
//

#include <iostream>
#include <queue>
#include <string>
#include <vector>

/**
 * @brief A struct representing a message to be queued
 * 
 */
struct QueuedMessage
{
    /**
     * @brief Construct a new Queued Message object
     * 
     * @param dest The destination of the message
     * @param data The data to be sent in the message
     */
    QueuedMessage(const std::string &dest, const std::vector<uint8_t> &data)
        : m_dest(dest),
          m_data(data)
    {
    }

    std::string m_dest; /**< The destination of the message */
    std::vector<uint8_t> m_data; /**< The data to be sent in the message */
};

/**
 * @brief The main function
 * 
 * @return int 
 */
int main()
{
    // Create a queue of QueuedMessage objects
    std::queue<QueuedMessage> m_sendMessageQueue;

    // Enqueue some messages
    m_sendMessageQueue.push(QueuedMessage("Destination1", {1, 2, 3, 4, 5}));
    m_sendMessageQueue.push(QueuedMessage("Destination2", {6, 7, 8, 9, 10}));

    // Check the size of the queue
    std::cout << "Queue size: " << m_sendMessageQueue.size() << std::endl;

    // Dequeue and process messages
    while (!m_sendMessageQueue.empty())
    {
        //front returns the reference to the first element in the queue
        QueuedMessage& message = m_sendMessageQueue.front();

        //Calling pop here will destroy the object
        // so don't call it here otherwise results will be undefined
        //m_sendMessageQueue.pop();

        std::cout << "Destination: " << message.m_dest << std::endl;
        std::cout << "Data: ";
        
        for (uint8_t data : message.m_data)
        {
            std::cout << static_cast<int>(data) << " ";
        }
        std::cout << std::endl;

        // Dequeue the message here after processing
        m_sendMessageQueue.pop();

    }

    // Check if the queue is empty
    if (m_sendMessageQueue.empty())
    {
        std::cout << "Queue is empty." << std::endl;
    }

    return 0;
}
