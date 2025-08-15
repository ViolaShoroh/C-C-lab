#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

class Perceptron 
{
    public:
    explicit Perceptron(int n) 
    {
        for (int i = 0; i < n; i++) 
        {
            this->weights.push_back(rand() % 10 + 1); //this - указывает на объект, для которого вызывается функция
            this->in_weights.push_back(1.0); //вставить новый элемент в конец вектора, который увеличивает размер вектора на 1.
        }
        this->delta = rand() % 10 + 1.1;
        this->eps = 2;
    }
    vector<double> weights, in_weights;
    double delta;
    double eps;

double forward(vector<double> weights, double delta) 
{
    double sum = 0;
    for (int i = 0; i < this->weights.size(); i++) 
    {
      sum += this->weights[i] * weights[i];
    }
    return sum + delta;
}

double sigmoid(int x) 
{
    return 1.0 / (1.0 + exp(-x));
}

void correct() 
{
    this->delta += this->eps * this->diffsigmoid(this->delta);
    for (int i = 0; i < weights.size(); i++) 
    {
        this->weights[i] += this->eps * this->weights[i] * this->diffsigmoid(forward(this->weights, this->delta));
    }
}

double diffsigmoid(int x) 
{
    return (1 - this->sigmoid(x)) * sigmoid(x);
}

void machine_learn() 
{
    double finaldiff = 1e-3;
    int ops = 1;
    double y, y1, diff;
    do 
    {
      cout << ops << " ";
      y = forward(this->in_weights, this->delta);
      cout << this->delta << " ";
      this->correct();
      y1 = forward(this->in_weights, this->delta);
      cout << this->delta << " ";
      diff = fabs(y1 - y);
      ops++;

      for (int j = 0; j < this->weights.size(); j++) 
      {
        cout << this->weights[j] << " ";
      }
      cout << y << " " << y1 << "\n";
    } while (diff > finaldiff);
    cout << "DONE! " << diff;
}
};

int main() 
{
    Perceptron perc(3);
    perc.machine_learn();
    return 0;
}