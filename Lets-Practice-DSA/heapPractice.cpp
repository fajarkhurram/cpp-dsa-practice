#include <iostream>
#include <string>
using namespace std;

struct Task
{
    string name;
    int priority;
    int order;      // Keeps insertion order
};

class PriorityQueue
{
private:
    Task heap[100];  //task type ki array
    int size;
    int orderCounter;

    // Compare two tasks
    bool higherPriority(Task a, Task b)
    {
        if (a.priority > b.priority)
            return true;

        if (a.priority == b.priority && a.order < b.order)
            return true;

        return false;
    }

    // Move inserted element upward
    void upHeapify(int index)
    {
        while (index > 0)
        {
            int parent = (index - 1) / 2;

            if (higherPriority(heap[index], heap[parent]))
            {
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else
                break;
        }
    }

    // Restore heap after deletion
    void downHeapify(int index)
    {
        while (true)
        {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < size &&
                higherPriority(heap[left], heap[largest]))
            {
                largest = left;
            }

            if (right < size &&
                higherPriority(heap[right], heap[largest]))
            {
                largest = right;
            }

            if (largest != index)
            {
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else
                break;
        }
    }

public:
    PriorityQueue()
    {
        size = 0;
        orderCounter = 0;
    }

    // Insert Task
    void enqueue(string taskName, int priority)
    {
        if (size == 100)
        {
            cout << "Priority Queue is Full!\n";
            return;
        }

        heap[size].name = taskName;
        heap[size].priority = priority;
        heap[size].order = orderCounter++;

        upHeapify(size);

        size++;

        cout << "Task Added Successfully.\n";
    }

    // Remove Highest Priority Task
    void dequeue()
    {
        if (size == 0)
        {
            cout << "Priority Queue is Empty.\n";
            return;
        }

        cout << "\nRemoved Task : "
             << heap[0].name
             << " (Priority "
             << heap[0].priority
             << ")\n";

        heap[0] = heap[size - 1];

        size--;

        downHeapify(0);
    }

    // Show Highest Priority Task
    void peek()
    {
        if (size == 0)
        {
            cout << "Priority Queue is Empty.\n";
            return;
        }

        cout << "\nHighest Priority Task\n";
        cout << "Task : " << heap[0].name << endl;
        cout << "Priority : " << heap[0].priority << endl;
    }

    // Display Heap
    void display()
    {
        if (size == 0)
        {
            cout << "Priority Queue is Empty.\n";
            return;
        }

        cout << "\nCurrent Heap\n";

        for (int i = 0; i < size; i++)
        {
            cout << "Task : "
                 << heap[i].name
                 << " | Priority : "
                 << heap[i].priority
                 << endl;
        }
    }
};

int main()
{
    PriorityQueue pq;

    int choice;
    string task;
    int priority;

    do
    {
        cout << "\n========== PRIORITY QUEUE ==========\n";
        cout << "1. Add Task\n";
        cout << "2. Remove Highest Priority Task\n";
        cout << "3. Peek Highest Priority Task\n";
        cout << "4. Display Queue\n";
        cout << "5. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:

            cout << "Enter Task Name : ";
            cin.ignore();
            getline(cin, task);

            cout << "Enter Priority : ";
            cin >> priority;

            pq.enqueue(task, priority);

            break;

        case 2:

            pq.dequeue();

            break;

        case 3:

            pq.peek();

            break;

        case 4:

            pq.display();

            break;

        case 5:

            cout << "Program Ended.\n";

            break;

        default:

            cout << "Invalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}