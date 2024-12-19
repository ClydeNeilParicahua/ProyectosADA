#include <iostream>
#include <string>
using namespace std;

class Producto {
public:
    int id_producto;    
    string nombre;       
    double precio;      
    Producto* siguiente; 

  
    Producto(int id, string n, double p) : id_producto(id), nombre(n), precio(p), siguiente(NULL) {}
};

class ListaProductos {
private:
    Producto* cabeza;  

public:
   
    ListaProductos() : cabeza(NULL) {}

  
    void agregarProducto(int id, string nombre, double precio) {
        Producto* nuevoProducto = new Producto(id, nombre, precio);
        
        if (cabeza == NULL) {
            cabeza = nuevoProducto; 
        } else {
            Producto* actual = cabeza;
            while (actual->siguiente != NULL) {
                actual = actual->siguiente; 
            }
            actual->siguiente = nuevoProducto; 
        }
    }

    void eliminarProducto(int id) {
        if (cabeza == NULL) {
            cout << "La lista está vacía." << endl;
            return;
        }

        if (cabeza->id_producto == id) {
            Producto* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
            return;
        }

        Producto* actual = cabeza;
        while (actual->siguiente != NULL && actual->siguiente->id_producto != id) {
            actual = actual->siguiente; 
        }

        if (actual->siguiente == NULL) {
            cout << "Producto no encontrado." << endl;
        } else {
            Producto* temp = actual->siguiente;
            actual->siguiente = actual->siguiente->siguiente;
            delete temp;
        }
    }

    void mostrarLista() {
        if (cabeza == NULL) {
            cout << "No hay productos en la lista." << endl;
            return;
        }

        Producto* actual = cabeza;
        while (actual != NULL) {
            cout << "ID: " << actual->id_producto << ", Nombre: " << actual->nombre << ", Precio: $" << actual->precio << endl;
            actual = actual->siguiente;
        }
    }

    ~ListaProductos() {
        while (cabeza != NULL) {
            Producto* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }
};

int main() {
    ListaProductos tienda; 

    tienda.agregarProducto(101, "Laptop", 1200.99);
    tienda.agregarProducto(102, "Teclado", 49.99);
    tienda.agregarProducto(103, "Raton", 25.50);

    cout << "Lista de productos:" << endl;
    tienda.mostrarLista(); 

    cout << "\nEliminando el producto con ID 102..." << endl;
    tienda.eliminarProducto(102); 

    cout << "\nLista de productos despues de eliminar:" << endl;
    tienda.mostrarLista(); 

    return 0;
}

