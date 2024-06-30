#include "pch.h"
#include <cliext/vector>

#include "RegistroVehicularClass.h"

RegistroVehicularClass::Nodo::Nodo(Vehiculo^ vehiculo)
{
	this->vehiculo = vehiculo;
	this->izquierda = nullptr;
	this->derecha = nullptr;
	//throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Nodo::Nodo()
{
	throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Vehiculo::Vehiculo(String^ Nro_placa, String^ marca, String^ modelo, int anio,String^tipoCombustible)
{
	this->Nro_placa = Nro_placa;
	this->marca = marca;
	this->modelo = modelo;
	this->anio = anio;
	this->tipoCombustible = tipoCombustible;
	inspecciones = gcnew List<Inspeccion^>();
	//throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Vehiculo::Vehiculo()
{
	this->Nro_placa = "";
	this->marca = "";
	this->modelo = "";
	this->anio = 0;
	//throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Nodo^ RegistroVehicularClass::ArbolBinarioBusqueda::insertarRecursivo(Nodo^ nodo, Vehiculo^ vehiculo)
{
	if (nodo == nullptr) {
		return gcnew Nodo(vehiculo);
	}
	if (String::Compare(vehiculo->Nro_placa, nodo->vehiculo->Nro_placa) < 0) {
		nodo->izquierda = insertarRecursivo(nodo->izquierda, vehiculo);
	}
	else {
		nodo->derecha = insertarRecursivo(nodo->derecha, vehiculo);
	}
	return nodo;

	// Código de depuración para imprimir un mensaje
	Console::WriteLine("Vehículo insertado: " + vehiculo->ToString());
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

RegistroVehicularClass::Nodo^ RegistroVehicularClass::ArbolBinarioBusqueda::buscarRecursivo(Nodo^ nodo, String^ nro_placa)
{

	if (nodo == nullptr || nodo->vehiculo->Nro_placa == nro_placa) {
		return nodo;
	}
	if (String::Compare(nro_placa, nodo->vehiculo->Nro_placa) < 0) {
		return buscarRecursivo(nodo->izquierda, nro_placa);
	}
	else {
		return buscarRecursivo(nodo->derecha, nro_placa);
	}
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

RegistroVehicularClass::Nodo^ RegistroVehicularClass::ArbolBinarioBusqueda::eliminarRecursivo(Nodo^ nodo, String^ nro_placa)
{

	if (nodo == nullptr) return nodo;

	if (String::Compare(nro_placa, nodo->vehiculo->Nro_placa) < 0) {
		nodo->izquierda = eliminarRecursivo(nodo->izquierda, nro_placa);
	}
	else if (String::Compare(nro_placa, nodo->vehiculo->Nro_placa) > 0) {
		nodo->derecha = eliminarRecursivo(nodo->derecha, nro_placa);
	}
	else {
		if (nodo->izquierda == nullptr) {
			return nodo->derecha;
		}
		else if (nodo->derecha == nullptr) {
			return nodo->izquierda;
		}

		Nodo^ temp = minValorNodo(nodo->derecha);
		nodo->vehiculo = temp->vehiculo;
		nodo->derecha = eliminarRecursivo(nodo->derecha, temp->vehiculo->Nro_placa);
	}
	return nodo;
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

void RegistroVehicularClass::ArbolBinarioBusqueda::GuardarNodo(StreamWriter^ archivo, Nodo^ nodo)
{
	if (nodo != nullptr) {
		archivo->WriteLine(nodo->vehiculo->Nro_placa + "," + nodo->vehiculo->marca + "," + nodo->vehiculo->modelo + "," + nodo->vehiculo->anio);
		GuardarNodo(archivo, nodo->izquierda);
		GuardarNodo(archivo, nodo->derecha);
	}
	//throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Nodo^ RegistroVehicularClass::ArbolBinarioBusqueda::minValorNodo(Nodo^ nodo)
{
	Nodo^ actual = nodo;
	while (actual->izquierda != nullptr) {
		actual = actual->izquierda;
	}
	return actual;
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

void RegistroVehicularClass::ArbolBinarioBusqueda::inOrdenRecursivo(Nodo^ nodo, List<Vehiculo^>^ vehiculos)
{
	if (nodo != nullptr) {
		inOrdenRecursivo(nodo->izquierda, vehiculos);
		vehiculos->Add(nodo->vehiculo);
		inOrdenRecursivo(nodo->derecha, vehiculos);
	}
	//throw gcnew System::NotImplementedException();
}

void RegistroVehicularClass::ArbolBinarioBusqueda::insertar(Vehiculo^ vehiculo)
{
	raiz = insertarRecursivo(raiz, vehiculo);
	//throw gcnew System::NotImplementedException();
}

RegistroVehicularClass::Vehiculo^ RegistroVehicularClass::ArbolBinarioBusqueda::buscar(String^ nro_placa)
{

	Nodo^ resultado = buscarRecursivo(raiz, nro_placa);
	return resultado == nullptr ? nullptr : resultado->vehiculo;
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

void RegistroVehicularClass::ArbolBinarioBusqueda::eliminar(String^ nro_placa)
{
	raiz = eliminarRecursivo(raiz, nro_placa);
	//throw gcnew System::NotImplementedException();
}

System::Collections::Generic::List<RegistroVehicularClass::Vehiculo^>^ RegistroVehicularClass::ArbolBinarioBusqueda::listarVehiculos()
{
	System::Collections::Generic::List<Vehiculo^>^ vehiculos = gcnew System::Collections::Generic::List<Vehiculo^>();
	inOrdenRecursivo(raiz, vehiculos);
	return vehiculos;
	//throw gcnew System::NotImplementedException();
	// TODO: Insertar una instrucción "return" aquí
}

void RegistroVehicularClass::ArbolBinarioBusqueda::guardarEnArchivo(String^ nombreArchivo)
{
	StreamWriter^ archivo = gcnew StreamWriter(nombreArchivo);
	GuardarNodo(archivo, raiz);
	archivo->Close();
	//throw gcnew System::NotImplementedException();
}



void RegistroVehicularClass::ArbolBinarioBusqueda::cargarDesdeArchivo(String^ nombreArchivo)
{
	StreamReader^ archivo = gcnew StreamReader(nombreArchivo);
	while (!archivo->EndOfStream) {
		String^ linea = archivo->ReadLine();
		cli::array<String^>^ partes = linea->Split(',');
		if (partes->Length == 5) {
			String^ placa = partes[0];
			String^ marca = partes[1];
			String^ modelo = partes[2];
			int anio = Convert::ToInt32(partes[3]);
			String^ combustible = partes[4];
			insertar(gcnew Vehiculo(placa, marca, modelo, anio,combustible));
		}
	}
	archivo->Close();
}


