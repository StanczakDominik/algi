using namespace std;

// template <class T>
// class STACK
// {
//   public:
//     STACK();
//     bool IsEmpty();
//     void Push(T);
//     T Pop();
// };
//
// template <class T>
// class QUEUE
// {
//   public:
//     QUEUE();
//     bool IsEmpty();
//     void Put(T);
//     T Get();
// };

//na tablicach
template <class T>
class STACK
{
private:
  T *sArr;
  int i;
public:
  STACK(int nMax)
    {sArr=new T[nMax]; i=0;}
  ~STACK()
    {delete[] sArr;}

  bool IsEmpty()
    {return i==0;}
  void Push(T v)
    {sArr[i++] = v;}
  T Pop()
    {return sArr[--i];}
};

//na listach wskaźnikowych
template <class T>
class STACK2
{
  private:
    struct node
    {
      T v;
      node *next;
      node (T _v, node *_next){v=_v; next=_next;}
    };
    node *head;
  public:
    STACK2()
      {head = nullptr;}
    bool IsEmpty()
      {return head==nullptr;}
    void Push(T v)
      {head = new node(v, head);}
    T Pop()
      {T v=head->v; node *p = head; head=head->next; delete p; return v;}
};

template <class T>
class QUEUE
{
  private:
    T *sArr;
    int i1, i2, nMax;
  public:
    QUEUE(int _nMax)
      {nMax = _nMax; sArr = new T[nMax]; i1=i2=0;}
    ~QUEUE()
      {delete[] sArr;}

    bool IsEmpty()
      {return i1==i2;}
    void Put(T v)
    {
      sArr[i1++]=v;
      i1=i1%nMax;
    }
    T Get()
    {
      T v = sArr[i2++];
      i2=i2%nMax;
      return v;
    }
};

template <class T>
class QUEUE2
{
private:
  struct node
  {
    T v;
    node *next;
    node(T _v)
    {
      v=_v;
      next=nullptr;
    }
  };
  node *head, *tail;

public:
  QUEUE2()
  {
    head = tail = nullptr;
  }

  bool IsEmpty()
  {
    return head==nullptr;
  }
  void Put(T v)
  {
    node *p = new node(v);
    if (head)   //nie trzeba ruszac heada
      tail -> next = p;
    else
    {
      head = tail = p;
      tail = p;
    }
  }
  T Get()
  {
    T v = head->v;
    node *p=head;
    head = head->next;
    delete p;
    return v;
  }
};

int main()
{
  return 0;
}
