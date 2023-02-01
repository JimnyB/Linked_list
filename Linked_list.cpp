#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // Constructor with data and next
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class Storage
{

public:
    Node *head_ref;
    /** Default constructor
     *
     */
    Storage() { head_ref = NULL; };

    /** Create a Node to hold the data, then put it at the head of the list.
     * @param text The data for the new node
     */

    void push(int data)
    {
        // Allocating space for a new node
        Node *new_node = new Node(data);
        // Setting the "new_node to the next in the list"
        new_node->next = head_ref;
        // Assigning the head reference to the new node
        head_ref = new_node;
        return;
    }
    /** Remove the head Node and return its data.
     *
     * @param [out] The data (only valid if return true)
     * @return True if there is a node to return
     */
    bool pop(int &pop)
    {
        if (head_ref == NULL)
        {
            // If there is nothing to pop, returning false
            return false;
        }
        // Node pointer to temp variable enabling the removal of the head of the list
        Node *temp = head_ref;
        head_ref = head_ref->next;
        pop = temp->data;
        // Deleting the temp ensuring there is no memory loss
        delete temp;
        return true;
    }

    /**
     * Return the data from the head Node, without removing it.
     *
     * @param [out] The data (only valid if return true)
     * @return True if text has been returned successfully (there is a node)
     */

    bool peek(int &peek)
    {

        if (head_ref == NULL)
        {
            return false;
        }
        else
        {
            peek = head_ref->data;
            return true;
        }
    }
    // Checking if the list is empty returning true if it is empty
    bool isEmpty()
    {
        if (head_ref == NULL)
            return true;
        else
            return false;
    }

    /**
     * Swaps the nodes at position i and j.
     *
     * @return Returns true if successful, otherwise false (e.g. outside range)
     */

    bool swap(int i, int j)
    {
        if (i == j)
            return true;

        // Search for i, itterating through with counti
        int counti = 0;
        Node *previousi = NULL, *currenti = head_ref;
        while (counti++ != i)
        {

            previousi = currenti;
            currenti = currenti->next;
        }
        // Search for j, itterating through with countj
        int countj = 0;
        Node *previousj = NULL, *currentj = head_ref;
        while (countj++ != j)
        {
            previousj = currentj;
            currentj = currentj->next;
        }
        // if they are NULL there is no swap to be made
        if (currenti == NULL || currentj == NULL)
            return false;

        // if i is not head of the list
        if (previousi != NULL)
            previousi->next = currentj;
        else
        // else make j the new head of the list
            head_ref = currentj;

        // if j is not head of the list
        if (previousj != NULL)
            previousj->next = currenti;
        else
        // make i the new head
            head_ref = currenti;
            
        //swapping the ->next
        Node *temp = currentj->next;
        currentj->next = currenti->next;
        currenti->next = temp;

        return true;
    }

    void print_list()
    {
        Node *node = head_ref;
        while (node != NULL)
        {
            cout << " " << node->data;
            node = node->next;
        }
        cout << endl;
    }
};

int main()
{
    int peek = -1;
    int pop = -1;
    bool isEmpty = false;
    Storage *s = new Storage();

    s->push(3);
    s->push(2);
    s->push(1);
    s->peek(peek);
    s->pop(pop);
    s->isEmpty();

 /*
    cout << std::boolalpha;
    cout << pop << endl;
    cout << peek << endl;
    cout << isEmpty << endl;
    cout << "the list consists of: " << endl;
    s->print_list();
    s->swap(1, 2);
    s->print_list();
*/
    return 0;
}
