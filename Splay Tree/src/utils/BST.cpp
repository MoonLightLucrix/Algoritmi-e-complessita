#include "BST.hpp"

template<class T>
Nodo<T>::Nodo(T info, Nodo<T>*up, Nodo<T>*sx, Nodo<T>*dx): info(info), up(up), sx(sx), dx(dx) {}

template<class T>
Nodo<T>::~Nodo(){}

template<class T>
void Nodo<T>::setUp(Nodo<T>*up)
{
    this->up=up;
}

template<class T>
Nodo<T>*Nodo<T>::getUp() const
{
    return up;
}

template<class T>
void Nodo<T>::setSx(Nodo<T>*sx)
{
    this->sx=sx;
}

template<class T>
Nodo<T>*Nodo<T>::getSx() const
{
    return sx;
}

template<class T>
void Nodo<T>::setDx(Nodo<T>*dx)
{
    this->dx=dx;
}

template<class T>
Nodo<T>*Nodo<T>::getDx() const
{
    return dx;
}

template<class T>
void Nodo<T>::setInfo(T info)
{
    this->info=info;
}

template<class T>
T Nodo<T>::getInfo() const
{
    return info;
}

template<class T>
void BST<T>::trapianta(Nodo<T>*a, Nodo<T>*b)
{
    if(!a->getUp())
    {
        radice=b;
    }
    else if(a->getUp()->getSx()==a)
    {
        a->getUp()->setSx(b);
    }
    else if(a->getUp()->getDx()==a)
    {
        a->getUp()->setDx(b);
    }
    if(b)
    {
        b->setUp(a->getUp());
    }
}

template <class T>
void BST<T>::inorder(Nodo<T>*a, size_t&i) const
{
    if(a)
    {
        inorder(a->getSx(),i);
        std::cout<<a->getInfo()<<((i<=s-2)?", ":"");
        i-=-1;
        inorder(a->getDx(),i);
    }
}

template <class T>
void BST<T>::postorder(Nodo<T>*a, size_t&i) const
{
    if(a)
    {
        postorder(a->getSx(),i);
        postorder(a->getDx(),i);
        std::cout<<a->getInfo()<<((i<=s-2)?", ":"");
        i-=-1;
    }
}

template <class T>
void BST<T>::preorder(Nodo<T>*a, size_t&i) const
{
    if(a)
    {
        std::cout<<a->getInfo()<<((i<=s-2)?", ":"");
        i-=-1;
        preorder(a->getSx(),i);
        preorder(a->getDx(),i);
    }
}

template<class T>
Nodo<T>*BST<T>::min(Nodo<T>*a) const
{
    if(a)
    {
        while(a->getSx())
        {
            a=a->getSx();
        }
    }
    return a;
}

template<class T>
Nodo<T>* BST<T>::max(Nodo<T>*a) const
{
    if(a)
    {
        while(a->getDx())
        {
            a=a->getDx();
        }
    }
    return a;
}

template<class T>
void BST<T>::postorderClear(Nodo<T>*a)
{
    if(a)
    {
        postorderClear(a->getSx());
        postorderClear(a->getDx());
        delete a;
        s-=1;
    }
}

template<class T>
Nodo<T>* BST<T>::find(T x)
{
    Nodo<T>*a=radice;
    while((a) && (a->getInfo()!=x))
    {
        a=(x>=a->getInfo())?a->getDx():a->getSx();
    }
    return a;
}

template<class T>
BST<T>* BST<T>::sxRotate(Nodo<T>*a)
{
    if((a) && (a->getDx()))
    {
        trapianta(a,a->getDx());
        a->setUp(a->getDx());
        a->setDx(a->getUp()->getSx());
        if(a->getDx())
        {
            a->getDx()->setUp(a);
        }
        a->getUp()->setSx(a);
    }
    return this;
}

template<class T>
BST<T>* BST<T>::dxRotate(Nodo<T>*a)
{
    if((a) && (a->getSx()))
    {
        trapianta(a,a->getSx());
        a->setUp(a->getSx());
        a->setSx(a->getUp()->getDx());
        if(a->getSx())
        {
            a->getSx()->setUp(a);
        }
        a->getUp()->setDx(a);
    }
    return this;
}

template<class T>
BST<T>::BST(): radice(nullptr), lastInsert(nullptr), s(0) {}

template<class T>
BST<T>::~BST()
{
    clear();
}

template<class T>
size_t BST<T>::getSize() const
{
    return s;
}

template <class T>
bool BST<T>::isEmpty() const
{
    return (!s);
}

template<class T>
BST<T>* BST<T>::insert(T x)
{
    Nodo<T>*a=new Nodo<T>(x);
    if(isEmpty())
    {
        radice=a;
    }
    else
    {
        Nodo<T>*b=radice;
        Nodo<T>*c;
        while(b)
        {
            c=b;
            b=(x>=b->getInfo())?b->getDx():b->getSx();
        }
        a->setUp(c);
        if(x>=c->getInfo())
        {
            c->setDx(a);
        }
        else
        {
            c->setSx(a);
        }
    }
    lastInsert=a;
    s-=-1;
    return this;
}

/*template <class T>
BST<T>* BST<T>::remove(T x)
{
    Nodo<T>*a=find(x);
    if(a)
    {
        if(!a->getDx())
        {
            trapianta(a,a->getSx());
        }
        else if(!a->getSx())
        {
            trapianta(a,a->getDx());
        }
        else if((a->getSx()) && (a->getDx()))
        {
            Nodo<T>*b=min(a->getDx());
            if(b->getUp()!=a)
            {
                trapianta(b,b->getDx());
                b->setDx(a->getDx());
                b->getDx()->setUp(b);
            }
            trapianta(a,b);
            b->setSx(a->getSx());
            b->getSx()->setUp(b);
        }
        delete a;
        s-=1;
    }
    return this;
}*/

template<class T>
BST<T>* BST<T>::remove(T x)
{
    Nodo<T>*a=find(x);
    if(a)
    {
        if(!a->getDx())
        {
            trapianta(a,a->getSx());
        }
        else if(!a->getSx())
        {
            trapianta(a,a->getDx());
        }
        else if((a->getSx()) && (a->getDx()))
        {
            Nodo<T>*b=max(a->getSx());
            if(b->getUp()!=a)
            {
                trapianta(b,b->getSx());
                b->setSx(a->getSx());
                b->getSx()->setUp(b);
            }
            trapianta(a,b);
            b->setDx(a->getDx());
            b->getDx()->setUp(b);
        }
        delete a;
        s-=1;
    }
    return this;
}

template<class T>
bool BST<T>::contains(T x)
{
    return (find(x));
}

/*template<class T>
BST<T>* BST<T>::sxRotate(T x)
{
    return sxRotate(find(x));
}*/

/*template<class T>
BST<T>* BST<T>::dxRotate(T x)
{
    return dxRotate(find(x));
}*/

template<class T>
BST<T>* BST<T>::clear()
{
    postorderClear(radice);
    radice=nullptr;
    lastInsert=nullptr;
    return this;
}

template<class T>
void BST<T>::stampaInorder() const
{
    size_t i=0;
    std::cout<<"[";
    inorder(radice,i);
    std::cout<<"]";
    std::cout<<std::endl;
}

template<class T>
void BST<T>::stampaPostorder() const
{
    size_t i=0;
    std::cout<<"[";
    postorder(radice,i);
    std::cout<<"]";
    std::cout<<std::endl;
}

template<class T>
void BST<T>::stampaPreorder() const
{
    size_t i=0;
    std::cout<<"[";
    preorder(radice,i);
    std::cout<<"]";
    std::cout<<std::endl;
}

template<class U>
std::ostream& operator <<(std::ostream &str, BST<U>&t)
{
    size_t i=0;
    str<<"[";
    t.inorder(t.radice,i);
    str<<"]";
    return str;
}

template<class T>
Nodo<T>* SplayTree<T>::find(T x)
{
    Nodo<T>*a=radice;
    Nodo<T>*b;
    while((a) && (a->getInfo()!=x))
    {
        b=a;
        a=(x>=a->getInfo())?a->getDx():a->getSx();
    }
    (a)?splay(a):splay(b);
    return a;
}

template<class T>
bool SplayTree<T>::zig(Nodo<T>*a) const
{
    return (a->getUp()->getSx()==a);
}

template<class T>
bool SplayTree<T>::zigzig(Nodo<T>*a) const
{
    if(a->getUp()->getUp()->getSx())
    {
        return (a->getUp()->getUp()->getSx()->getSx()==a);
    }
    return false;
}

template<class T>
bool SplayTree<T>::zigzag(Nodo<T>*a) const
{
    if(a->getUp()->getUp()->getSx())
    {
        return (a->getUp()->getUp()->getSx()->getDx()==a);
    }
    return false;
}

template<class T>
bool SplayTree<T>::zag(Nodo<T>*a) const
{
    return (a->getUp()->getDx()==a);
}

template<class T>
bool SplayTree<T>::zagzag(Nodo<T>*a) const
{
    if(a->getUp()->getUp()->getDx())
    {
        return (a->getUp()->getUp()->getDx()->getDx()==a);
    }
    return false;
}

template<class T>
bool SplayTree<T>::zagzig(Nodo<T>*a) const
{
    if(a->getUp()->getUp()->getDx())
    {
        return (a->getUp()->getUp()->getDx()->getSx()==a);
    }
    return false;
}

template<class T>
BST<T>* SplayTree<T>::splay(Nodo<T>*a)
{
    while(a->getUp())
    {
        if(!a->getUp()->getUp())
        {
            if(zig(a))
            {
                dxRotate(a->getUp());
            }
            else if(zag(a))
            {
                sxRotate(a->getUp());
            }
        }
        else
        {
            if(zigzig(a))
            {
                dxRotate(a->getUp()->getUp());
                dxRotate(a->getUp());
            }
            else if(zigzag(a))
            {
                sxRotate(a->getUp());
                dxRotate(a->getUp());
            }
            else if(zagzag(a))
            {
                sxRotate(a->getUp()->getUp());
                sxRotate(a->getUp());
            }
            else if(zagzig(a))
            {
                dxRotate(a->getUp());
                sxRotate(a->getUp());
            }
        }
    }
    return this;
}

template<class T>
SplayTree<T>::SplayTree(): BST<T>() {}

template<class T>
SplayTree<T>::~SplayTree(){}

/*template<class T>
BST<T>* SplayTree<T>::insert(T x)
{
    Nodo<T>*a=new Nodo<T>(x);
    if(isEmpty())
    {
        radice=a;
    }
    else
    {
        Nodo<T>*b=radice;
        Nodo<T>*c;
        while(b)
        {
            c=b;
            b=(x>=b->getInfo())?b->getDx():b->getSx();
        }
        splay(c);
        if(x>=c->getInfo())
        {
            a->setDx(c->getDx());
            if(c->getDx())
            {
                c->getDx()->setUp(a);
            }
            c->setDx(a);
        }
        else
        {
            a->setSx(c->getSx());
            if(c->getSx())
            {
                c->getSx()->setUp(a);
            }
            c->setSx(a);
        }
        splay(a);
    }
    s-=-1;
    return this;
}*/

template<class T>
BST<T>* SplayTree<T>::insert(T x)
{
    BST<T>::insert(x);
    return splay(lastInsert);
}