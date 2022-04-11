#include <iostream>
using namespace std;

class Nod
{
protected:

    int info;
    Nod *next;

public:
    Nod()
    {
        info = 0;
        next = NULL;
    }
    Nod(int info)
    {
        this->info = info;
        this->next = NULL;
    }

    Nod(Nod const& copy_nod) : next(copy_nod.next), info(copy_nod.info)
    { }

    virtual ~Nod()
    {
        Nod *next = NULL;
    }

    friend class LSI;
    friend class LDI;

    Nod& operator= (const Nod& n1)
    {
        info = n1.info;
        Nod *next = n1.next;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Nod *n);
    friend istream& operator>>(istream& in, Nod *n);
};

ostream& operator<<(ostream& out, const Nod *n)
{
    out<<n->info;
    return out;
}
istream& operator>>(istream& in, Nod *n)
{
    in>>n->info;
    in>>n->next;
    return in;
}

class Nod_dublu : public Nod
{
protected:

    Nod *ante;

public:
    Nod_dublu()
    {
        info = 0;
        next = NULL;
        ante = NULL;
    }
    Nod_dublu(int info)
    {
        this->info = info;
        this->next = NULL;
        this->ante = NULL;
    }

    Nod_dublu(Nod_dublu const& copy_nod) : ante(copy_nod.ante)
    { }

    friend class LDI;

    ~Nod_dublu()
    {
        ante = NULL;
    }

    Nod_dublu& operator= (const Nod_dublu& n1)
    {
        info = n1.info;
        Nod *next = n1.next;
        Nod *ante = n1.ante;
        return *this;
    }

    friend ostream& operator<<(ostream& out, const Nod_dublu *n);
    friend istream& operator>>(istream& in, Nod_dublu *n);
};

ostream& operator<<(ostream& out, const Nod_dublu *n)
{
    out<<n->info;
    return out;
}
istream& operator>>(istream& in, Nod_dublu *n)
{
    in>>n->info;
    in>>n->next;
    in>>n->ante;
    return in;
}

class LDI
{
protected:

    Nod_dublu *head;
public:
    LDI()
    {
        head = NULL;
    }

    LDI(Nod_dublu *n)
    {
        head = n;
    }

    virtual ~LDI()
    {
        Nod *p = new Nod_dublu();
        p = head;
        Nod *q = new Nod_dublu();
        q = head;
        while(p!=NULL)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }

    LDI& operator= (const LDI& l1)
    {
        Nod *c = new Nod_dublu();
        c = l1.head;
        return *this;
    }

    void print(Nod_dublu* head)
    {
        Nod *aux = new Nod_dublu();
        aux = head;
        if (aux != NULL)
        {
            cout << aux->info;
            aux = aux->next;
        }
        while (aux != NULL)
        {
            cout <<aux->info;
            aux = aux->next;
        }
    }

    void insert_elem(int info)
    {
        Nod_dublu *temp = new Nod_dublu();
        temp->info = info;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            Nod *p = new Nod_dublu();
            p = head;

            while(p->next != NULL)
                p = p->next;
            p->next = temp;
            temp->ante = p;

        }
    }
};

class LSI : public LDI
{
protected:

    Nod *head;
public:
    LSI()
    {
        head = NULL;
    }

    LSI(Nod *n)
    {
        head = n;
    }

    ~LSI()
    {
        Nod *p = new Nod();
        p = head;
        Nod *q = new Nod();
        q = head;
        while(p!=NULL)
        {
            q=p->next;
            delete p;
            p=q;
        }
    }

    LSI& operator= (const LSI& l1)
    {
        Nod *c = new Nod();
        c = l1.head;
        return *this;
    }

    void print(Nod* head)
    {
        Nod *aux = new Nod();
        aux = head;
        if (aux != NULL)
        {
            cout << aux->info;
            aux = aux->next;
        }
        while (aux != NULL)
        {
            cout <<aux->info;
            aux = aux->next;
        }
    }

    void insert_elem(int info)
    {
        Nod *temp = new Nod();
        temp->info = info;
        if(head == NULL)
        {
            head = temp;
        }
        else
        {
            Nod *p = head;

            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = temp;

        }
    }
};

int main()
{
    cout<<"Care sunt elementele listei?";
    return 0;
}
