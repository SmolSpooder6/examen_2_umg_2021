// Examen_productos.cpp : 

#include <mysql.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main(){
    int opcion, opcion_ingreso;
    int q_estado;

    MYSQL* conectar;
    MYSQL_ROW fila;
    MYSQL_RES* resultado;
    conectar = mysql_init(0);
    conectar = mysql_real_connect(conectar, "localhost", "usr_examen_producto", "exem", "db_examen_productos", 3306, NULL, 0);

    //variables de marca
    string marca,insert,consulta, marca_old, marca_new, marca_del;
    //variables de productos
    string producto, id_marca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso;

    //variables de productos en modificar
    string conf, set, producto_old, producto_new;
    string producto_del;
    //variables de producto
    const char* ip;
    //variables de marca
    const char* i;
    const char* c;
    const char* m;
    const char* d;

    if (conectar) {
        //cout << "conexion exitosa\n" << endl;

        menu:
        system("cls");
        cout << "Gerardo Castillo 1290-20-20942" << endl;

        cout << "\n\nMenu de Opciones" << endl;

        cout << "1. Ingrsar nuevos datos" << endl;
        cout << "2. Mostrar datos" << endl;
        cout << "3. Modificar datos" << endl;
        cout << "4. Eliminar datos" << endl;
        cout << "5. SALIR" << endl;

        cout << "\nIngrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            //opciones de ingreso
            case 1:
                system("cls");
                cout << "que desea ingresar?\n" << endl;
                cout << "1. Ingresar Marcas" << endl;
                cout << "2. Ingresar productos" << endl;
                cout << "3. Regresar" << endl;
                cout << "ingrese opcion: ";
                cin >> opcion_ingreso;

                switch (opcion_ingreso) {
                    //ingreso de marca
                case 1:
                    system("cls");

                    
                    cout << "ingrese marca: ";
                    cin >> marca;
                    insert = "INSERT INTO marcas(marca) values('" + marca + "')";
                    i = insert.c_str();
                    q_estado = mysql_query(conectar, i);
                    if (!q_estado) {
                        cout << "ingreso exitoso" << endl;
                    }
                    else {
                        cout << "error al ingresar " << endl;
                    }
                    _getch();
                    goto menu;

                case 2:
                    //ingrso de producto
                    system("cls");
             
                    cout << "ingrese Produco: ";
                    cin >> producto;
                    cout << "ingrese id de la marca: ";
                    cin >> id_marca;
                    cout << "Ingrese descripcion del producto: ";
                    cin >> descripcion;
                    cout << "Ingrese Imagen del producto: ";
                    cin >> imagen;
                    cout << "Ingrese Precio de costo: ";
                    cin >> precio_costo;
                    cout << "Ingrese Precio de venta: ";
                    cin >> precio_venta;
                    cout << "Ingrese cantidad de existencias del producto: ";
                    cin >> existencia;
                    cout << "Ingrese fecha de ingreso del producto FORMATO (YY-MM-DD HH:MM:SS): ";
                    cin >> fecha_ingreso;
                    insert = "INSERT INTO productos(producto,idMarca,descripcion,imagen,precio_costo,precio_venta,existencia,fecha_ingreso) VALUES('" + producto + "','" + id_marca + "','" + descripcion + "','" + imagen + "','" + precio_costo + "','" + precio_venta + "','" + existencia + "','" + fecha_ingreso + "')";
                   
                    //confirmacion posible
                    
                    ip = insert.c_str();
                    q_estado = mysql_query(conectar, ip);
                    if (!q_estado) {
                        cout << "ingreso exitoso" << endl;
                    }
                    else {
                        cout << "error al ingresar " << endl;
                    }
                    _getch();
                    goto menu;

                case 3:
                    goto menu;
                }


                
                break;
             

            case 2:

                //opciones de visualizacion
                system("cls");
                cout << "que desea visualizar?\n" << endl;
                cout << "1. Ver todas las Marcas" << endl;
                cout << "2. Ver todos los productos" << endl;
                cout << "3. Regresar" << endl;
                cout << "ingrese opcion: ";
                cin >> opcion_ingreso;

                switch (opcion_ingreso) {
                    //ingreso de marca
                case 1:
                    //lectura de marcas
                    system("cls");
                    cout << "-------Marcas-------" << endl;
                    consulta = "SELECT *FROM marcas;";
                    c = consulta.c_str();
                    q_estado = mysql_query(conectar, c);
                    if (!q_estado) {
                        resultado = mysql_store_result(conectar);
                        while (fila = mysql_fetch_row(resultado)) {
                            cout << fila[0] << ": " << fila[1] << endl;

                        }

                    }
                    else {
                        cout << "error al leer datos " << endl;
                    }

                    _getch();
                    goto menu;
                    break;

                case 2:
                    //lectura de productos
                    system("cls");
                    cout << "---------------------------Productos---------------------------" << endl;
                    consulta = "SELECT *FROM productos;";
                    c = consulta.c_str();
                    q_estado = mysql_query(conectar, c);
                    if (!q_estado) {
                        resultado = mysql_store_result(conectar);
                        while (fila = mysql_fetch_row(resultado)) {
                            cout << "id producto: "<< fila[0] << "\nproducto: " << fila[1] << "\nid marca: " << fila[2] << "\ndescripcion: " << fila[3] << "\nimagen: " << fila[4] << "\nprecio costo: " << fila[5] << "\nprecio venta: " << fila[6] << "\nexistencia: " << fila[7] << "\nfecha ingreso: " << fila[8] <<"\n\n"<<endl;
                        }
                    }
                    else {
                        cout << "error al leer datos " << endl;
                    }
                    _getch();
                    goto menu;
                    break;
                    
                case 3:
                    goto menu;
                }

            case 3:
                // modificacion de datos
                system("cls");
                cout << "que desea Modificar?\n" << endl;
                cout << "1. Modificar Marcas" << endl;
                cout << "2. Modificar productos" << endl;
                cout << "3. Regresar" << endl;
                cout << "ingrese opcion: ";
                cin >> opcion_ingreso;

                switch (opcion_ingreso) {
                case 1:
                    // modificacion de marca
                    system("cls");
                    cout << "ingrese marca que desea modificar: ";
                    cin >> marca_old;
                    cout << "ingrese la marca modificada: ";
                    cin >> marca_new;
                    insert = "UPDATE marcas SET marca=('" + marca_new + "') WHERE marca = ('" + marca_old + "')";
                    m = insert.c_str();
                    q_estado = mysql_query(conectar, m);
                    if (!q_estado) {
                        cout << "ingreso exitoso" << endl;
                    }
                    else {
                        cout << "error al ingresar " << endl;
                    }
                    _getch();
                    goto menu;

                case 2:
                    //modificacion de productos
                        system("cls");
                        cout << "Opciones: producto, idMarca, descripcion, imagen, precio_costo, precio_venta, existencia, fecha_ingreso" << endl;
                        cout << "Ingrese que desea modificar: ";
                        cin >> set;
                        
                    

                    cout << "Ingrese '" + set + "' del producto desea modificar: ";
                    cin >> producto_old;
                    cout << "Ingrese el nuevo '" + set + "' modificado: ";
                    cin >> producto_new;
                    insert = "UPDATE productos SET " + set + " = ('" + producto_new + "') WHERE " + set + " = ('" + producto_old + "');";

                    m = insert.c_str();
                    q_estado = mysql_query(conectar, m);
                    if (!q_estado) {
                        cout << "ingreso exitoso" << endl;
                    }
                    else {
                        cout << "error al ingresar " << endl;
                    }
                    _getch();
                    goto menu;

                case 3:
                    goto menu;
                }
                
                

            case 4:
                // Eliminacion de datos
                system("cls");
                cout << "que desea Eliminar?\n" << endl;
                cout << "1. Eliminar Marcas" << endl;
                cout << "2. Eliminar productos" << endl;
                cout << "3. Regresar" << endl;
                cout << "ingrese opcion: ";
                cin >> opcion_ingreso;

                switch (opcion_ingreso) {
                case 1:
                
                    system("cls");
                    cout << "Ingrese marca que desea eliminar: ";
                    cin >> marca_del;
                    insert = "DELETE FROM marcas WHERE marca = ('" + marca_del + "')";
                    d = insert.c_str();
                    q_estado = mysql_query(conectar, d);
                    if (!q_estado) {
                        cout << "ingreso exitoso" << endl;
                    }
                    else {
                        cout << "error al ingresar " << endl;
                    }
                    _getch();
                    goto menu;

                case 2:

                    system("cls");
                    cout << "Ingrese id del producto que desea eliminar: ";
                    cin >> producto_del;
                    insert = "DELETE FROM productos WHERE idProductos = ('" + producto_del + "')";
                    d = insert.c_str();
                    q_estado = mysql_query(conectar, d);
                    if (!q_estado) {
                        cout << "borrado exitoso" << endl;
                    }
                    else {
                        cout << "error al borrar" << endl;
                    }
                    _getch();
                    goto menu;


                case 3:
                    goto menu;
                }       

            case 5:

                system("cls");
                return 0;

        }

    }
    else {
        cout << "error en la conexion\n" << endl;
    }

}

