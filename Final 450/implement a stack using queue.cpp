//Function to push an element into stack using two queues.
void QueueStack :: push(int x)
{
        // Your Code
        q1.push(x);
        return;
}

//Function to pop an element from stack using two queues. 

void recurPop(queue<int> &q1, queue<int> &q2){
    if(q1.empty()) return;
    int a = q1.front();
    q1.pop();
    recurPop(q1, q2);
    q2.push(a);
}

int QueueStack :: pop()
{
        // Your Code
        if(q1.empty()) return -1;
        recurPop(q1, q2);
        
        int to_return = q2.front();
        q2.pop();
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        
        return to_return;
        
}