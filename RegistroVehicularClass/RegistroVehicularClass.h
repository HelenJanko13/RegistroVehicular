#pragma once
#include <vector>
#include <iostream>
#include <string>

using namespace System;
using namespace System::IO;
using namespace std;
using namespace System::Collections::Generic;

namespace RegistroVehicularClass {

	public ref class Inspeccion {
	public:
		property DateTime^ fecha;
		property String^ resultado;

		Inspeccion(DateTime^ fecha, String^ resultado) {
			this->fecha = fecha;
			this->resultado = resultado;
		}
	};
	public ref class Vehiculo
	{
	public:
		property String^ Nro_placa;
		property String^ marca;
		property String^ modelo;
		property int anio;
		property String^ tipoCombustible;
		property List<Inspeccion^>^ inspecciones;

		Vehiculo(String^ Nro_placa, String^ marca, String^ modelo, int anio,String^tipoCombustible);
		Vehiculo();
		virtual String^ ToString() override {
			return "  Placa: " + Nro_placa + "\r\n" +
				"     Marca: " + marca + "\r\n" +
				"     Modelo: " + modelo + "\r\n" +
				"     Anio: " + anio.ToString() + "\r\n"+
			    "     Tipo de Combustible: " + tipoCombustible + "\r\n";
			    
		}
		void AgregarInspeccion(Inspeccion^ inspeccion) {
			inspecciones->Add(inspeccion);
		}

		bool HaSidoInspeccionadoEsteAnio() {
			int anioActual = DateTime::Now.Year;
			for each (Inspeccion ^ inspeccion in inspecciones) {
				if (inspeccion->fecha->Year == anioActual) {
					return true;
				}
			}
			return false;
		}
		// Método ToString actualizado para incluir inspecciones (opcional)
		virtual String^ ToStringInspeccion()  {
			String^ info = " Placa: " + Nro_placa + ", Marca: " + marca + ", Modelo: " + modelo + ", Año: " + anio.ToString() + ", Tipo de Combustible: " + tipoCombustible;
			for each (Inspeccion ^ inspeccion in inspecciones) {
				info += "\n Inspeccion: Fecha: " + inspeccion->fecha->ToString("dd/MM/yyyy") + ", Resultado: " + inspeccion->resultado;
			}
			return info;
		}


		String^ GetNro_placa() { return Nro_placa; }
		String^ GetMarca() { return marca; }
		String^ GetModelo() { return modelo; }
		int GetAnio() { return anio; }
		String^ GetTipoCombustible() { return tipoCombustible; }

		void SetNro_placa(String^ Nro_placa) { this->Nro_placa = Nro_placa; }
		void SetMarca(String^ marca) { this->marca = marca; }
		void SetModelo(String^ modelo) { this->modelo = modelo; }
		void SetAnio(int anio) { this->anio = anio; }
		void SetTipoCombustible(String^ tipoCombustible) { this->tipoCombustible=tipoCombustible; }

		// TODO: Agregue aquí los métodos de esta clase.
	};

	public ref class Nodo {
	public:
		Vehiculo^ vehiculo;
		Nodo^ izquierda;
		Nodo^ derecha;

		Nodo(Vehiculo^ vehiculo);

		Nodo();

		Vehiculo^ GetVehiculo() { return vehiculo; }
		void SetVehiculo(Vehiculo^ vehiculo) { this->vehiculo = vehiculo; }
		Nodo^ GetIzquierda() { return izquierda; }
		void SetIzquierda(Nodo^ izquierda) { this->izquierda = izquierda; }
		Nodo^ GetDerecha() { return derecha; }
		void SetDerecha(Nodo^ derecha) { this->derecha = derecha; }


	};

	public ref class ArbolBinarioBusqueda {
	private:
		Nodo^ raiz;
		//property List<Vehiculo^>^ vehiculos;

		Nodo^ insertarRecursivo(Nodo^ nodo, Vehiculo^ vehiculo);
		Nodo^ buscarRecursivo(Nodo^ nodo, String^ nro_placa);
		Nodo^ eliminarRecursivo(Nodo^ nodo, String^ nro_placa);
		void GuardarNodo(StreamWriter^ archivo, Nodo^ nodo);
		Nodo^ minValorNodo(Nodo^ nodo);
		void inOrdenRecursivo(Nodo^ nodo, List<Vehiculo^>^ vehiculos);

	public:
		ArbolBinarioBusqueda() { raiz = nullptr; }

		void insertar(Vehiculo^ vehiculo);
		Vehiculo^ buscar(String^ nro_placa);
		void eliminar(String^ nro_placa);
		//List<Vehiculo^>^ listarVehiculos();
		System::Collections::Generic::List<Vehiculo^>^ listarVehiculos();



	public:
		void guardarEnArchivo(String^ nombreArchivo);

		void cargarDesdeArchivo(String^ nombreArchivo);



	public:
		void RegistroVehicularClass::ArbolBinarioBusqueda::agregarInspeccionAVehiculo(String^ nro_placa, Inspeccion^ inspeccion) {
			Nodo^ nodo = buscarRecursivo(raiz, nro_placa);
			if (nodo != nullptr && nodo->vehiculo != nullptr) {
				nodo->vehiculo->AgregarInspeccion(inspeccion);
			}
			else {
				throw gcnew System::Exception("Vehículo no encontrado");
			}
		}
		List<Vehiculo^>^ listarVehiculosNoInspeccionadosEsteAnio() {
			List<Vehiculo^>^ vehiculosNoInspeccionados = gcnew List<Vehiculo^>();
			listarVehiculosNoInspeccionadosEsteAnioRecursivo(raiz, vehiculosNoInspeccionados);
			return vehiculosNoInspeccionados;
		}

		void listarVehiculosNoInspeccionadosEsteAnioRecursivo(Nodo^ nodo, List<Vehiculo^>^ vehiculosNoInspeccionados) {
			if (nodo != nullptr) {
				if (!nodo->vehiculo->HaSidoInspeccionadoEsteAnio()) {
					vehiculosNoInspeccionados->Add(nodo->vehiculo);
				}
				listarVehiculosNoInspeccionadosEsteAnioRecursivo(nodo->izquierda, vehiculosNoInspeccionados);
				listarVehiculosNoInspeccionadosEsteAnioRecursivo(nodo->derecha, vehiculosNoInspeccionados);
			}
		}





	};
}