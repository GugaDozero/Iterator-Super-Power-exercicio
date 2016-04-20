#include <iostream>
#include <vector>


#include "superiterator.h"

using namespace std;


class Aluno
{
public:
    Aluno(int nota) : m_nota(nota) {}
    inline double nota() { return this->m_nota; }


private:
    double m_nota;
};


int main()
{
    vector<Aluno> vetor;

    for(int i = 1; i <= 5; ++i)
        vetor.push_back(i);


    IteratorSuperPower<Aluno, vector> iterator(vetor, &Aluno::nota, "<=", 5);


    try
    {
        while(iterator.hasPrevious())
        {
            cout << iterator.previous().nota() << " ";
        }

        cout << endl;

        while(iterator.hasNext())
        {
            cout << iterator.next().nota() << " ";
        }
    }
    catch(std::exception &except)
    {
        cerr << "\nAn error has ocurred: " << except.what() << endl;
    }


    cin.get();

    return 0;
}
