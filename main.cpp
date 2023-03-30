#include <iostream>
#include <vector>

using namespace std;

template<typename T>

class Queue 
{
private:
  vector<T> queue;

public:
  void Add(T t) {
    queue.push_back(t);
  }
 
  void GetQueue() {
    for (auto i = queue.begin(); i != queue.end(); i++) {
      cout << *i << endl;
    }
  }

  void LaunchQueue() {
    char answer;
    
    if (queue.empty()) {
      cout << "Queue is empty!" << endl;
    }

    cout << "Edit element in the queue?\n->";
    cin >> answer;

    if (answer == 'y') {
      EditElement();
    }

    while (!queue.empty()) {
      GetQueue();
      queue.erase(queue.begin());
      cout << endl;
    }
  }

  void ClearQueue() {
    char answer;
    cout << "Clear your queue y/n?\n-> ";
    cin >> answer;

    if (answer == 'y') { 
      queue.clear();
      cout << "Queue cleared!" << endl;
    }
    else { 
      cout << "Canceled clear!" << endl;
    }
  }

  void EditElement() {
    string edited_data;
    int index;
    cout << "Which element edit?\n-> ";
    cin >> index;
    cout << "Change data: ";
    cin >> edited_data;
    queue.at(index-1) = edited_data;
  }
};

int main() { 
  Queue<string> str_queue;
  string text;
  char answer;
  bool loop = true;
  
  // Manuala objektu veidosana
  while (loop) {
    cout << "Enter text to your object\n-> ";
    cin >> text;
    str_queue.Add(text);
    system("clear");
    cout << "Continue y/n?\n-> ";
    cin >> answer;
    system("clear");
    if (answer != 'y' ) {
      loop = false;
    }
  }

  // Ja slinkums pasam veidot objektus
  /*
  str_queue.Add("1st order");
  str_queue.Add("2nd order");
  str_queue.Add("3rd order");
  str_queue.Add("4th order");
  str_queue.Add("5th order");*/

  str_queue.ClearQueue(); // Erti ja gribat paskatities, kas notiek ar tuksu rindu
  str_queue.LaunchQueue(); // Simulacija
}
