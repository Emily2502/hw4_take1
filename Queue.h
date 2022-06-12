//
// Created by 97250 on 6/12/2022.
//

#ifndef HW4_TAKE1_QUEUE_H
#define HW4_TAKE1_QUEUE_H

template<class T>
class Queue
{
public:

    /**
     * C'tor of Queue class
     *
     * @return
     *      A new instance of Queue.
    */
    Queue() = default;

    /**
     * Copy c'tor of Queue class
     *
     * @param Queue& - Reference to Queue to copy.
     * @return
     *      A new instance of Queue.
     */
    Queue(const Queue&);

    /**
     * Assignment operator of Queue class
     *
     * @return
     *      reference to queue.
    */
    Queue<T>& operator=(const Queue<T>&);

    /**
     * D'tor of Queue class
     *
     * @return
     *      void
    */
    ~Queue();

    /**
     * Adds a new member to the back of a given queue
     *
     * @return
     *      void
    */
    void pushBack(T member);

    /**
     * Returns a reference to the first member of a given queue
     *
     * @return
     *      reference to the first member of tha given queue
    */
    T& front();
    const T& front() const;

    /**
     * Deletes the first member of a given queue
     *
     * @return
     *      void
    */
    void popFront();

    /**
     * Returns the size of a given queue
     *
     * @return
     *      the size of a given queue
    */
    int size() const;


    /**
     * Iterator class for Queue
    */
    class Iterator;

    /**
     * ConstIterator class for const Queue
    */
    class ConstIterator;

    /**
     * Beginning iterator for Queue
     * @return
     *      new iterator that points to the start of a given queue
    */
    Iterator begin() const;

    /**
     * End iterator for Queue
     * @return
     *      new iterator that points after the end of a given queue
    */
    Iterator end() const;

    /**
     * New type for exceptions
    */
    class EmptyQueue {};

private:
    struct Node;
    Node* m_front = nullptr;
    Node* m_back = nullptr;
    void deleteQueue(Node* front);
};

/** --------------------------------------------------------------------------------------------------
 * Implementing Node struct and private methods:
 * Queue is a linked list with pointers to the front and back and Node is the struct we use to
 * implement said linked list
----------------------------------------------------------------------------------------------------*/

template<class T>
struct Queue<T>::Node
{
    T m_data;
    Node* m_next;
};

template<class T>
void Queue<T>::deleteQueue(Queue::Node *front)
{
    if (front == nullptr)
    {
        return;
    }
    deleteQueue(front->m_next);
    delete front;
}

/** --------------------------------------------------------------------------------------------------
 * Implementing Queue class:
 * at first we implement copy c'tor, d'tor and assignment operator.
 * secondly we implement functions requested.
----------------------------------------------------------------------------------------------------*/

template<class T>
Queue<T>::Queue(const Queue<T>& queue)
{
    Node* nodeToCopy = queue.m_front;
    try
    {
        while (nodeToCopy != nullptr)
        {

            pushBack(nodeToCopy->m_data);
            nodeToCopy = nodeToCopy->m_next;
        }
    }
    catch (...)
    {
        deleteQueue(m_front);
        throw;
    }
    // m_back changed in pushBack
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue<T> &queue)
{
    if (this == &queue)
    {
        return *this;
    }

    Queue<T> temp;
    Node* nodeToCopy = queue.m_front;
    try
    {
        while (nodeToCopy != nullptr)
        {
            temp.pushBack(nodeToCopy->m_data);
            nodeToCopy = nodeToCopy->m_next;
        }
    }
    catch (...)
    {
        deleteQueue(temp.m_front);
        throw;
    }
    deleteQueue(m_front);
    m_front = temp.m_front;
    m_back = temp.m_back;
    return *this;
}

template<class T>
Queue<T>::~Queue()
{
    deleteQueue(m_front);
}

template<class T>
void Queue<T>::pushBack(T member)
{
    Node* temp = new Node;
    // no need to throw bad_alloc

    temp->m_data = member;
    temp->m_next = nullptr;

    if (m_front == nullptr)
    {
        m_front = temp;
        m_back = temp;
    }
    else
    {
        m_back->m_next = temp;
        m_back = m_back->m_next;
    }
}

template<class T>
T& Queue<T>::front()
{
    if(m_front == nullptr)
    {
        throw EmptyQueue();
    }
    return m_front->m_data;
}

template<class T>
const T& Queue<T>::front() const
{
    if(m_front == nullptr)
    {
        throw EmptyQueue();
    }
    return m_front->m_data;
}


template<class T>
void Queue<T>::popFront()
{
    if (m_front == nullptr)
    {
        throw EmptyQueue();
    }
    Node* toDelete = m_front;
    m_front = m_front->m_next;
    delete toDelete;
}


template<class T>
int Queue<T>::size() const
{
    int result = 0;
    Node* tempNode = m_front;
    while (tempNode != nullptr)
    {
        ++result;
        tempNode = tempNode->m_next;
    }
    return result;
}


template<class T, class Condition>
void transform(Queue<T>& queue, Condition condition)
{
    for(typename Queue<T>::Iterator it = queue.begin(); it != queue.end(); ++it)
    {
        condition(*it);
    }
}


template<class T, class Condition>
Queue<T> filter(const Queue<T>& constQueue, Condition condition)
{
    Queue<T> result;
    for(typename Queue<T>::ConstIterator it = constQueue.begin(); it != constQueue.end(); ++it)
    {
        if (condition(*it))
        {
            result.pushBack(*it);
        }
    }
    return result;
}


/** --------------------------------------------------------------------------------------------------
 * Implementing Iterator class:
 * we provide three operator as requested (*, !=, ++)
----------------------------------------------------------------------------------------------------*/

template<class T>
class Queue<T>::Iterator
{
public:

    /**
     * New type for exceptions
    */
    class InvalidOperation {};

    T& operator*() const;
    Iterator& operator++();
    bool operator!=(const Iterator&) const;

    Iterator(const Iterator&) = default;
    ~Iterator() = default;

private:
    Node* m_node;
    explicit Iterator(Node* node) : m_node(node) {}
    friend class Queue<T>;
};

template<class T>
T& Queue<T>::Iterator::operator*() const
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    return m_node->m_data;
}

template<class T>
typename Queue<T>::Iterator& Queue<T>::Iterator::operator++()
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::Iterator::operator!=(const Iterator& iterator) const
{
    return m_node != iterator.m_node;
}

template<class T>
typename Queue<T>::Iterator Queue<T>::begin() const
{
    return Iterator(m_front);
}

template<class T>
typename Queue<T>::Iterator Queue<T>::end() const
{
    return Iterator(nullptr);
}

/** --------------------------------------------------------------------------------------------------
 * Implementing ConstIterator class:
 * we provide three operator as requested (*, !=, ++)
----------------------------------------------------------------------------------------------------*/


template<class T>
class Queue<T>::ConstIterator
{
public:

    /**
     * New type for exceptions
    */
    class InvalidOperation {};

    const T& operator*() const;
    ConstIterator& operator++();
    bool operator!=(const Iterator&);

    ConstIterator(const ConstIterator&) = default;
    ~ConstIterator() = default;

    /**
     * C'tor to make ConstIterator
    */
    ConstIterator(const Iterator& iterator) : m_node(iterator.m_node) {}

private:
    const Node* m_node;
    explicit ConstIterator(const Node* node) : m_node(node) {}
};

template<class T>
const T& Queue<T>::ConstIterator::operator*() const
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    return m_node->m_data;
}

template<class T>
typename Queue<T>::ConstIterator& Queue<T>::ConstIterator::operator++()
{
    if(m_node == nullptr)
    {
        throw InvalidOperation();
    }
    m_node = m_node->m_next;
    return *this;
}

template<class T>
bool Queue<T>::ConstIterator::operator!=(const Iterator& iterator)
{
    return m_node != iterator.m_node;
}

#endif //HW4_TAKE1_QUEUE_H
