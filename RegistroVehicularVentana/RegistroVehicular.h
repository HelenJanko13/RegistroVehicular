#pragma once

//#include "RegistroVehicularClases.h"
#include "vector"
#include "string"
#include "iostream"
#include <list>
#include <cliext/vector>
#include <msclr\marshal_cppstd.h>
 using namespace std;
//#include "ArbolBinarioBusqueda.h"
using namespace RegistroVehicularClass;


namespace RegistroVehicularVentana {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de RegistroVehicular
	/// </summary>
	public ref class RegistroVehicular : public System::Windows::Forms::Form
	{
	public:
		RegistroVehicular(void)
		{
			InitializeComponent();
            arbol = gcnew RegistroVehicularClass::ArbolBinarioBusqueda();
            cargarDatos();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~RegistroVehicular()
		{
			if (components)
			{
				delete components;
			}
		}

        //listViewVehiculos->View = View::Details;
    private: System::Windows::Forms::ListBox^ listaVehiculos;
    private:System::Windows::Forms::Button^ btnAgregar;
    private:System::Windows::Forms::Button^ btnBuscar;
    private:System::Windows::Forms::Button^ btnEditar;
    private:System::Windows::Forms::Button^ btnEliminar;
    private:System::Windows::Forms::Button^ btnListar;
    private:System::Windows::Forms::Button^ btnGuardar;
    private:System::Windows::Forms::Button^ btnCargar;

    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Label^ label5;

    private: System::Windows::Forms::TextBox^ textBoxPlaca;



    private: System::Windows::Forms::TextBox^ textBoxMarca;

    private: System::Windows::Forms::TextBox^ textBoxModelo;
    private: System::Windows::Forms::TextBox^ textBoxAnio;


	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
         ArbolBinarioBusqueda^ arbol;
    private: System::Windows::Forms::GroupBox^ groupBox1;
    private: System::Windows::Forms::GroupBox^ groupBox2;
    private: System::Windows::Forms::GroupBox^ groupBox3;

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->textBoxPlaca = (gcnew System::Windows::Forms::TextBox());
            this->textBoxMarca = (gcnew System::Windows::Forms::TextBox());
            this->textBoxModelo = (gcnew System::Windows::Forms::TextBox());
            this->textBoxAnio = (gcnew System::Windows::Forms::TextBox());
            this->listaVehiculos = (gcnew System::Windows::Forms::ListBox());
            this->btnAgregar = (gcnew System::Windows::Forms::Button());
            this->btnBuscar = (gcnew System::Windows::Forms::Button());
            this->btnEditar = (gcnew System::Windows::Forms::Button());
            this->btnEliminar = (gcnew System::Windows::Forms::Button());
            this->btnListar = (gcnew System::Windows::Forms::Button());
            this->btnGuardar = (gcnew System::Windows::Forms::Button());
            this->btnCargar = (gcnew System::Windows::Forms::Button());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(12, 25);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(65, 19);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Nro Placa";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(13, 156);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(32, 19);
            this->label2->TabIndex = 3;
            this->label2->Text = L"Año";
            this->label2->Click += gcnew System::EventHandler(this, &RegistroVehicular::label2_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(242, -9);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(212, 28);
            this->label3->TabIndex = 2;
            this->label3->Text = L"REGISTRO VEHICULAR";
            this->label3->Click += gcnew System::EventHandler(this, &RegistroVehicular::label3_Click);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(12, 113);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(51, 19);
            this->label4->TabIndex = 3;
            this->label4->Text = L"Modelo";
            this->label4->Click += gcnew System::EventHandler(this, &RegistroVehicular::label4_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 9.749999F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(12, 71);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(46, 19);
            this->label5->TabIndex = 4;
            this->label5->Text = L"Marca";
            this->label5->Click += gcnew System::EventHandler(this, &RegistroVehicular::label5_Click);
            // 
            // textBoxPlaca
            // 
            this->textBoxPlaca->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBoxPlaca->ForeColor = System::Drawing::SystemColors::WindowText;
            this->textBoxPlaca->Location = System::Drawing::Point(99, 26);
            this->textBoxPlaca->MaxLength = 10;
            this->textBoxPlaca->Multiline = true;
            this->textBoxPlaca->Name = L"textBoxPlaca";
            this->textBoxPlaca->Size = System::Drawing::Size(119, 25);
            this->textBoxPlaca->TabIndex = 16;
            this->textBoxPlaca->TextChanged += gcnew System::EventHandler(this, &RegistroVehicular::textBox1_TextChanged);
            // 
            // textBoxMarca
            // 
            this->textBoxMarca->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBoxMarca->ForeColor = System::Drawing::SystemColors::WindowText;
            this->textBoxMarca->Location = System::Drawing::Point(99, 114);
            this->textBoxMarca->Multiline = true;
            this->textBoxMarca->Name = L"textBoxMarca";
            this->textBoxMarca->Size = System::Drawing::Size(119, 25);
            this->textBoxMarca->TabIndex = 18;
            // 
            // textBoxModelo
            // 
            this->textBoxModelo->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBoxModelo->ForeColor = System::Drawing::SystemColors::WindowText;
            this->textBoxModelo->Location = System::Drawing::Point(99, 71);
            this->textBoxModelo->Multiline = true;
            this->textBoxModelo->Name = L"textBoxModelo";
            this->textBoxModelo->Size = System::Drawing::Size(119, 25);
            this->textBoxModelo->TabIndex = 19;
            // 
            // textBoxAnio
            // 
            this->textBoxAnio->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->textBoxAnio->ForeColor = System::Drawing::SystemColors::WindowText;
            this->textBoxAnio->Location = System::Drawing::Point(99, 157);
            this->textBoxAnio->MaxLength = 10;
            this->textBoxAnio->Multiline = true;
            this->textBoxAnio->Name = L"textBoxAnio";
            this->textBoxAnio->Size = System::Drawing::Size(119, 25);
            this->textBoxAnio->TabIndex = 20;
            this->textBoxAnio->TextChanged += gcnew System::EventHandler(this, &RegistroVehicular::textBox4_TextChanged);
            // 
            // listaVehiculos
            // 
            this->listaVehiculos->BackColor = System::Drawing::SystemColors::InactiveBorder;
            this->listaVehiculos->Font = (gcnew System::Drawing::Font(L"Microsoft Himalaya", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->listaVehiculos->FormattingEnabled = true;
            this->listaVehiculos->ItemHeight = 20;
            this->listaVehiculos->Location = System::Drawing::Point(306, 34);
            this->listaVehiculos->Name = L"listaVehiculos";
            this->listaVehiculos->Size = System::Drawing::Size(343, 304);
            this->listaVehiculos->TabIndex = 0;
            this->listaVehiculos->SelectedIndexChanged += gcnew System::EventHandler(this, &RegistroVehicular::listaVehiculos_SelectedIndexChanged);
            // 
            // btnAgregar
            // 
            this->btnAgregar->Location = System::Drawing::Point(10, 10);
            this->btnAgregar->Name = L"btnAgregar";
            this->btnAgregar->Size = System::Drawing::Size(86, 23);
            this->btnAgregar->TabIndex = 40;
            this->btnAgregar->Text = L"Agregar";
            this->btnAgregar->UseVisualStyleBackColor = true;
            this->btnAgregar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnAgregar_Click);
            // 
            // btnBuscar
            // 
            this->btnBuscar->Location = System::Drawing::Point(10, 39);
            this->btnBuscar->Name = L"btnBuscar";
            this->btnBuscar->Size = System::Drawing::Size(75, 23);
            this->btnBuscar->TabIndex = 2;
            this->btnBuscar->Text = L"Buscar";
            this->btnBuscar->UseVisualStyleBackColor = true;
            this->btnBuscar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnBuscar_Click);
            // 
            // btnEditar
            // 
            this->btnEditar->Location = System::Drawing::Point(109, 10);
            this->btnEditar->Name = L"btnEditar";
            this->btnEditar->Size = System::Drawing::Size(75, 23);
            this->btnEditar->TabIndex = 3;
            this->btnEditar->Text = L"Editar";
            this->btnEditar->UseVisualStyleBackColor = true;
            this->btnEditar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnEditar_Click);
            // 
            // btnEliminar
            // 
            this->btnEliminar->Location = System::Drawing::Point(200, 10);
            this->btnEliminar->Name = L"btnEliminar";
            this->btnEliminar->Size = System::Drawing::Size(75, 23);
            this->btnEliminar->TabIndex = 4;
            this->btnEliminar->Text = L"Eliminar";
            this->btnEliminar->UseVisualStyleBackColor = true;
            this->btnEliminar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnEliminar_Click);
            // 
            // btnListar
            // 
            this->btnListar->Location = System::Drawing::Point(109, 68);
            this->btnListar->Name = L"btnListar";
            this->btnListar->Size = System::Drawing::Size(75, 23);
            this->btnListar->TabIndex = 5;
            this->btnListar->Text = L"Listar";
            this->btnListar->UseVisualStyleBackColor = true;
            this->btnListar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnListar_Click);
            // 
            // btnGuardar
            // 
            this->btnGuardar->Location = System::Drawing::Point(200, 39);
            this->btnGuardar->Name = L"btnGuardar";
            this->btnGuardar->Size = System::Drawing::Size(75, 23);
            this->btnGuardar->TabIndex = 14;
            this->btnGuardar->Text = L"Guardar";
            this->btnGuardar->UseVisualStyleBackColor = true;
            this->btnGuardar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnGuardar_Click);
            // 
            // btnCargar
            // 
            this->btnCargar->Location = System::Drawing::Point(109, 39);
            this->btnCargar->Name = L"btnCargar";
            this->btnCargar->Size = System::Drawing::Size(75, 23);
            this->btnCargar->TabIndex = 15;
            this->btnCargar->Text = L"Cargar";
            this->btnCargar->UseVisualStyleBackColor = true;
            this->btnCargar->Click += gcnew System::EventHandler(this, &RegistroVehicular::btnCargar_Click);
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->label5);
            this->groupBox1->Controls->Add(this->label4);
            this->groupBox1->Controls->Add(this->label2);
            this->groupBox1->Controls->Add(this->label1);
            this->groupBox1->Controls->Add(this->textBoxPlaca);
            this->groupBox1->Controls->Add(this->textBoxMarca);
            this->groupBox1->Controls->Add(this->textBoxModelo);
            this->groupBox1->Controls->Add(this->textBoxAnio);
            this->groupBox1->Location = System::Drawing::Point(13, 34);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(245, 205);
            this->groupBox1->TabIndex = 41;
            this->groupBox1->TabStop = false;
            // 
            // groupBox2
            // 
            this->groupBox2->Controls->Add(this->btnEliminar);
            this->groupBox2->Controls->Add(this->btnEditar);
            this->groupBox2->Controls->Add(this->btnListar);
            this->groupBox2->Controls->Add(this->btnBuscar);
            this->groupBox2->Controls->Add(this->btnAgregar);
            this->groupBox2->Controls->Add(this->btnGuardar);
            this->groupBox2->Controls->Add(this->btnCargar);
            this->groupBox2->Location = System::Drawing::Point(2, 245);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(285, 105);
            this->groupBox2->TabIndex = 42;
            this->groupBox2->TabStop = false;
            // 
            // groupBox3
            // 
            this->groupBox3->Controls->Add(this->groupBox2);
            this->groupBox3->Controls->Add(this->label3);
            this->groupBox3->Controls->Add(this->groupBox1);
            this->groupBox3->Controls->Add(this->listaVehiculos);
            this->groupBox3->Location = System::Drawing::Point(10, 8);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(666, 355);
            this->groupBox3->TabIndex = 43;
            this->groupBox3->TabStop = false;
            // 
            // RegistroVehicular
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(688, 375);
            this->Controls->Add(this->groupBox3);
            this->Name = L"RegistroVehicular";
            this->Text = L"RegistroVehicular";
            this->Load += gcnew System::EventHandler(this, &RegistroVehicular::RegistroVehicular_Load);
            this->groupBox1->ResumeLayout(false);
            this->groupBox1->PerformLayout();
            this->groupBox2->ResumeLayout(false);
            this->groupBox3->ResumeLayout(false);
            this->groupBox3->PerformLayout();
            this->ResumeLayout(false);

        }
#pragma endregion
	private: System::Void RegistroVehicular_Load(System::Object^ sender, System::EventArgs^ e) {
	}
    
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
       }

           // Handlers for button clicks

           void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e) {
              String^ placaStr = textBoxPlaca->Text;
               String^ marcaStr = textBoxMarca->Text;
               String^ modeloStr = textBoxModelo->Text;
               int anio = Convert::ToInt32(textBoxAnio->Text);

               Vehiculo^ vehiculo = gcnew Vehiculo(placaStr, marcaStr, modeloStr, anio);
               arbol->insertar(vehiculo);
               MessageBox::Show("Vehículo agregado exitosamente.");
           }

           void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
               String^ placaStr = textBoxPlaca->Text;
               Vehiculo^ vehiculo = arbol->buscar(placaStr);
               if (vehiculo) {
                   textBoxMarca->Text = vehiculo->marca;
                   textBoxModelo->Text = vehiculo->modelo;
                   textBoxAnio->Text = vehiculo->anio.ToString();
                   MessageBox::Show("Vehículo encontrado.");
               }
               else {
                   MessageBox::Show("Vehículo no encontrado.");
               }
           }

           void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
               String^ placa = textBoxPlaca->Text;
               arbol->eliminar(placa);
               String^ marca = textBoxMarca->Text;
               String^ modelo = textBoxModelo->Text;
               int anio = Convert::ToInt32(textBoxAnio->Text);
               Vehiculo^ vehiculo = gcnew Vehiculo(placa, marca, modelo, anio);
               arbol->insertar(vehiculo);
               MessageBox::Show("Vehículo editado correctamente");
           }

           void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
               String^ placaStr = textBoxPlaca->Text;
               arbol->eliminar(placaStr);
               MessageBox::Show("Vehículo eliminado exitosamente.");
           }

           void btnListar_Click(System::Object^ sender, System::EventArgs^ e) {
               listaVehiculos->Items->Clear();
               System::Collections::Generic::List<Vehiculo^>^ vehiculos = arbol->listarVehiculos();
               for (int i = 0; i < vehiculos->Count; i++) {
                   Vehiculo^ vehiculo = vehiculos[i];
                   listaVehiculos->Items->Add(vehiculo->ToString());
               }

           }
          void btnGuardar_Click(System::Object^ sender, System::EventArgs^ e) {
               arbol->guardarEnArchivo("vehiculos.txt");
               MessageBox::Show("Datos guardados correctamente");
           }

           void btnCargar_Click(System::Object^ sender, System::EventArgs^ e) {
               arbol->cargarDesdeArchivo("vehiculos.txt");
               MessageBox::Show("Datos cargados correctamente");
           }

           void cargarDatos() {
               try {
                   arbol->cargarDesdeArchivo("vehiculos.txt");
               }
               catch (Exception^ ex) {
                   MessageBox::Show("No se pudieron cargar los datos iniciales: " + ex->Message);
               }
           }
    private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
    private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
    private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void listaVehiculos_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
