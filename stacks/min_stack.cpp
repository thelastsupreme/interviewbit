stack<int>mins;
stack<int>s;
MinStack::MinStack() {
    while(!s.empty())
        s.pop();
    while(!mins.empty())
        mins.pop();
}

void MinStack::push(int x) {
    s.push(x);
    if(mins.empty())
        mins.push(x);
    else
    {
        int a=mins.top();
        if(x<=a)
        {
            mins.push(x);
        }
        else
        {
            mins.push(a);
        }
    }

}

void MinStack::pop() {
    if(!s.empty())
        {
            s.pop();
            mins.pop();
        }

}

int MinStack::top() {
    if(!s.empty())
        return s.top();
    return -1;
}

int MinStack::getMin() {
    if(!mins.empty())
        return mins.top();
    return -1;
}
