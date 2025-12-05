#include <iostream>
#include "../header/base_type.h"
#include "../header/dynamic_list.h"
using namespace std;

string typeToString(TypeKind t) {
    switch (t) {
        case TypeKind::INT: return "INT";
        case TypeKind::FLOAT: return "FLOAT";
        case TypeKind::CHAR: return "CHAR";
        case TypeKind::STRING: return "STRING";
        case TypeKind::BOOL: return "BOOL";
    }
    return "UNKNOWN";
}

int main() {
    DynamicList list;

    // list.add(new Integer(10));
    // list.add(new Float(3.14f));
    // list.add(new String("hello"));
    // list.add(new Boolean(true));
    // list.add(new Character('A'));

    // cout << "List = ";
    // list.print();

    // cout << "Type of item[2] is: "
    //      << typeToString(list[2]->getType()) << endl;

    // list.removeAt(1);
    
    // cout << "After remove: ";
    // list.print();

      list.add(new Boolean(true));
      list.add(new String("ahmed"));
      cout<< typeToString(list[0]->getType())<<'\n';

      list.print();

    return 0;
}
