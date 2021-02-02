#pragma once
#include "MiniTip.h"

namespace WinFormsNewLife {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	private: WinFormsNewLife::MiniTip^ mf;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			mf = gcnew WinFormsNewLife::MiniTip();
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
			if (mf)
			{
				delete mf;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::PictureBox^ pictureBox1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(5, 7);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Встроенный";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::MenuBar;
			this->panel1->Location = System::Drawing::Point(-1, -2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(392, 34);
			this->panel1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::Window;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::DimGray;
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(-1, 26);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(392, 139);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Автособираемое оглавление 1";
			this->button1->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->toolTip1->SetToolTip(this->button1, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n\r\n");
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::Window;
			this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::Color::DimGray;
			this->button2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.Image")));
			this->button2->Location = System::Drawing::Point(-1, 165);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(392, 139);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Автособираемое оглавление 2\r\n";
			this->button2->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->toolTip2->SetToolTip(this->button2, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n\r\n");
			this->button2->UseVisualStyleBackColor = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::Window;
			this->button3->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button3->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::Color::DimGray;
			this->button3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.Image")));
			this->button3->Location = System::Drawing::Point(-1, 304);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(392, 139);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Ручное оглавление";
			this->button3->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->toolTip3->SetToolTip(this->button3, L"Оглавление, заполняемое \r\nвручную, независимо от               \r\nсодержимого доку"
				L"мента");
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::SystemColors::Window;
			this->button4->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button4->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button4.Image")));
			this->button4->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button4->Location = System::Drawing::Point(0, 443);
			this->button4->Margin = System::Windows::Forms::Padding(0);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(392, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"   Дополнительные оглавления с сайта Office.com";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button4->UseVisualStyleBackColor = false;
			this->button4->MouseEnter += gcnew System::EventHandler(this, &MyForm::button4_MouseEnter);
			this->button4->MouseLeave += gcnew System::EventHandler(this, &MyForm::button4_MouseLeave);
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::SystemColors::Window;
			this->button5->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button5->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button5.Image")));
			this->button5->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button5->Location = System::Drawing::Point(-1, 466);
			this->button5->Margin = System::Windows::Forms::Padding(0);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(392, 23);
			this->button5->TabIndex = 6;
			this->button5->Text = L"     Настраиваемое оглавление...\r\n\r\n";
			this->button5->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button5->UseVisualStyleBackColor = false;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::SystemColors::Window;
			this->button6->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button6->Location = System::Drawing::Point(0, 489);
			this->button6->Margin = System::Windows::Forms::Padding(0);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(392, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"   Удалить оглавление";
			this->button6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button6->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button6->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::Window;
			this->button7->FlatAppearance->BorderColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button7->Location = System::Drawing::Point(0, 512);
			this->button7->Margin = System::Windows::Forms::Padding(0);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(392, 23);
			this->button7->TabIndex = 8;
			this->button7->Text = L"   Сохранить выделенный фрагмент в коллекцию оглавлений...";
			this->button7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button7->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->button7->UseVisualStyleBackColor = false;
			// 
			// toolTip1
			// 
			this->toolTip1->ToolTipTitle = L"Автособираемое оглавление 1";
			// 
			// toolTip2
			// 
			this->toolTip2->ToolTipTitle = L"Автособираемое оглавление 2";
			this->toolTip2->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip2_Popup);
			// 
			// toolTip3
			// 
			this->toolTip3->ToolTipTitle = L"Ручное оглавление";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(375, 450);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(10, 10);
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseEnter);
			this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox1_MouseLeave);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(391, 536);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void toolTip2_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void button4_MouseEnter(System::Object^ sender, System::EventArgs^ e) {

	mf->x = this->Location.X + this->Size.Width + this->button4->Location.X - 1;
	mf->y = this->Location.Y + this->button4->Location.Y + 1;
	mf->Show();
	this->pictureBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
		static_cast<System::Int32>(static_cast<System::Byte>(240)));

}
private: System::Void button4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {

	this->pictureBox1->BackColor = System::Drawing::Color::White;
	mf->Hide();

}
private: System::Void pictureBox1_MouseEnter(System::Object^ sender, System::EventArgs^ e) {

	this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(215)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
		static_cast<System::Int32>(static_cast<System::Byte>(240)));
	this->button4_MouseEnter(sender, e);

}
private: System::Void pictureBox1_MouseLeave(System::Object^ sender, System::EventArgs^ e) {

	this->button4->BackColor = System::Drawing::Color::White;
	this->button4_MouseLeave(sender, e);

}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
