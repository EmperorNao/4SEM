#pragma once

namespace WinForms {

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
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
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
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:




	private: System::Windows::Forms::PictureBox^ pictureBox2;


	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel4;

	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ToolTip^ toolTip2;
	private: System::Windows::Forms::ToolTip^ toolTip3;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer1;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer2;

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Panel^ panel6;


	private: System::Windows::Forms::ToolTip^ toolTip4;

	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer5;
	private: System::Windows::Forms::ToolStripContainer^ toolStripContainer6;
	private: System::Windows::Forms::StatusStrip^ statusStrip1;












	protected:

	protected:












	protected:
	private: System::ComponentModel::IContainer^ components;

	protected:

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
			System::Windows::Forms::ToolTip^ toolTip1;
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->flowLayoutPanel2 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->toolStripContainer1 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->toolStripContainer2 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->toolStripContainer3 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->toolStripContainer4 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->toolTip2 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->toolTip3 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->toolTip4 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->toolStripContainer5 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->toolStripContainer6 = (gcnew System::Windows::Forms::ToolStripContainer());
			this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
			toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel4->SuspendLayout();
			this->toolStripContainer1->ContentPanel->SuspendLayout();
			this->toolStripContainer1->SuspendLayout();
			this->toolStripContainer2->ContentPanel->SuspendLayout();
			this->toolStripContainer2->SuspendLayout();
			this->toolStripContainer3->ContentPanel->SuspendLayout();
			this->toolStripContainer3->SuspendLayout();
			this->toolStripContainer4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel6->SuspendLayout();
			this->toolStripContainer5->ContentPanel->SuspendLayout();
			this->toolStripContainer5->SuspendLayout();
			this->toolStripContainer6->SuspendLayout();
			this->SuspendLayout();
			// 
			// toolTip1
			// 
			toolTip1->AutoPopDelay = 5000;
			toolTip1->BackColor = System::Drawing::SystemColors::Window;
			toolTip1->ForeColor = System::Drawing::Color::Black;
			toolTip1->InitialDelay = 500;
			toolTip1->ReshowDelay = 100;
			toolTip1->ToolTipTitle = L"Автособираемое оглавление 1";
			toolTip1->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip1_Popup);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->label3);
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Location = System::Drawing::Point(0, 5);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(418, 138);
			this->panel2->TabIndex = 4;
			toolTip1->SetToolTip(this->panel2, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"");
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::DimGray;
			this->label3->Location = System::Drawing::Point(4, 5);
			this->label3->Margin = System::Windows::Forms::Padding(1, 0, 3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(181, 16);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Автособираемое оглавление 1";
			toolTip1->SetToolTip(this->label3, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(9, 40);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(385, 97);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			toolTip1->SetToolTip(this->pictureBox1, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->flowLayoutPanel1);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->pictureBox2);
			this->panel1->Location = System::Drawing::Point(-4, 22);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(418, 138);
			this->panel1->TabIndex = 0;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::SystemColors::Menu;
			this->flowLayoutPanel1->Location = System::Drawing::Point(3, -11);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(412, 25);
			this->flowLayoutPanel1->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DimGray;
			this->label2->Location = System::Drawing::Point(4, 5);
			this->label2->Margin = System::Windows::Forms::Padding(1, 0, 3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 16);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Автособираемое оглавление 1";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(9, 40);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(385, 97);
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Menu;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::Color::DimGray;
			this->label1->Location = System::Drawing::Point(5, 7);
			this->label1->Margin = System::Windows::Forms::Padding(1, 0, 1, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(78, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Встроенный";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// flowLayoutPanel2
			// 
			this->flowLayoutPanel2->BackColor = System::Drawing::SystemColors::Menu;
			this->flowLayoutPanel2->Location = System::Drawing::Point(-1, -1);
			this->flowLayoutPanel2->Name = L"flowLayoutPanel2";
			this->flowLayoutPanel2->Size = System::Drawing::Size(412, 25);
			this->flowLayoutPanel2->TabIndex = 3;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button7);
			this->panel3->Controls->Add(this->label4);
			this->panel3->Controls->Add(this->pictureBox3);
			this->panel3->Location = System::Drawing::Point(-1, 165);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(418, 138);
			this->panel3->TabIndex = 4;
			this->toolTip2->SetToolTip(this->panel3, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::DimGray;
			this->label4->Location = System::Drawing::Point(4, 5);
			this->label4->Margin = System::Windows::Forms::Padding(1, 0, 3, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(181, 16);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Автособираемое оглавление 2";
			this->toolTip2->SetToolTip(this->label4, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(9, 40);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(385, 97);
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			this->toolTip2->SetToolTip(this->pictureBox3, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->toolStripContainer5);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->toolStripContainer1);
			this->panel4->Controls->Add(this->label5);
			this->panel4->Controls->Add(this->pictureBox4);
			this->panel4->Location = System::Drawing::Point(-1, 304);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(418, 138);
			this->panel4->TabIndex = 5;
			this->toolTip3->SetToolTip(this->panel4, L"Оглавление, заполняемое \r\nвручную, независимо от \r\nсодержимого документа\r\n");
			// 
			// panel5
			// 
			this->panel5->Location = System::Drawing::Point(0, 143);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(394, 26);
			this->panel5->TabIndex = 0;
			// 
			// toolStripContainer1
			// 
			this->toolStripContainer1->BottomToolStripPanelVisible = false;
			// 
			// toolStripContainer1.ContentPanel
			// 
			this->toolStripContainer1->ContentPanel->Controls->Add(this->button5);
			this->toolStripContainer1->ContentPanel->Controls->Add(this->button4);
			this->toolStripContainer1->ContentPanel->Controls->Add(this->button1);
			this->toolStripContainer1->ContentPanel->Controls->Add(this->toolStripContainer2);
			this->toolStripContainer1->ContentPanel->Size = System::Drawing::Size(391, 39);
			this->toolStripContainer1->LeftToolStripPanelVisible = false;
			this->toolStripContainer1->Location = System::Drawing::Point(0, 143);
			this->toolStripContainer1->Name = L"toolStripContainer1";
			this->toolStripContainer1->Size = System::Drawing::Size(391, 39);
			this->toolStripContainer1->TabIndex = 6;
			this->toolStripContainer1->Text = L"toolStripContainer1";
			this->toolStripContainer1->TopToolStripPanelVisible = false;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(6, -3);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(382, 27);
			this->button5->TabIndex = 6;
			this->button5->Text = L"button5";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(0, -3);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(390, 26);
			this->button4->TabIndex = 6;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(193, 0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// toolStripContainer2
			// 
			// 
			// toolStripContainer2.ContentPanel
			// 
			this->toolStripContainer2->ContentPanel->Controls->Add(this->button2);
			this->toolStripContainer2->ContentPanel->Controls->Add(this->listBox2);
			this->toolStripContainer2->ContentPanel->Controls->Add(this->listBox1);
			this->toolStripContainer2->ContentPanel->Controls->Add(this->toolStripContainer3);
			this->toolStripContainer2->ContentPanel->Size = System::Drawing::Size(150, 150);
			this->toolStripContainer2->Location = System::Drawing::Point(240, 4);
			this->toolStripContainer2->Name = L"toolStripContainer2";
			this->toolStripContainer2->Size = System::Drawing::Size(150, 175);
			this->toolStripContainer2->TabIndex = 1;
			this->toolStripContainer2->Text = L"toolStripContainer2";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(8, 8);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"button2";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(8, 8);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(120, 95);
			this->listBox2->TabIndex = 2;
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(8, 8);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(120, 95);
			this->listBox1->TabIndex = 1;
			// 
			// toolStripContainer3
			// 
			this->toolStripContainer3->BottomToolStripPanelVisible = false;
			// 
			// toolStripContainer3.ContentPanel
			// 
			this->toolStripContainer3->ContentPanel->Controls->Add(this->toolStripContainer4);
			this->toolStripContainer3->ContentPanel->Controls->Add(this->button3);
			this->toolStripContainer3->ContentPanel->Size = System::Drawing::Size(150, 175);
			this->toolStripContainer3->LeftToolStripPanelVisible = false;
			this->toolStripContainer3->Location = System::Drawing::Point(0, 0);
			this->toolStripContainer3->Name = L"toolStripContainer3";
			this->toolStripContainer3->Size = System::Drawing::Size(150, 175);
			this->toolStripContainer3->TabIndex = 0;
			this->toolStripContainer3->Text = L"toolStripContainer3";
			this->toolStripContainer3->TopToolStripPanelVisible = false;
			// 
			// toolStripContainer4
			// 
			this->toolStripContainer4->BottomToolStripPanelVisible = false;
			// 
			// toolStripContainer4.ContentPanel
			// 
			this->toolStripContainer4->ContentPanel->Size = System::Drawing::Size(387, 182);
			this->toolStripContainer4->LeftToolStripPanelVisible = false;
			this->toolStripContainer4->Location = System::Drawing::Point(-237, -7);
			this->toolStripContainer4->Name = L"toolStripContainer4";
			this->toolStripContainer4->Size = System::Drawing::Size(387, 182);
			this->toolStripContainer4->TabIndex = 2;
			this->toolStripContainer4->Text = L"toolStripContainer4";
			this->toolStripContainer4->TopToolStripPanelVisible = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(7, 28);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 37);
			this->button3->TabIndex = 1;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->ForeColor = System::Drawing::Color::DimGray;
			this->label5->Location = System::Drawing::Point(4, 5);
			this->label5->Margin = System::Windows::Forms::Padding(1, 0, 3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(116, 16);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Ручное оглавление";
			this->toolTip3->SetToolTip(this->label5, L"Оглавление, заполняемое \r\nвручную, независимо от \r\nсодержимого документа");
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(9, 40);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(385, 97);
			this->pictureBox4->TabIndex = 1;
			this->pictureBox4->TabStop = false;
			this->toolTip3->SetToolTip(this->pictureBox4, L"Оглавление, заполняемое \r\nвручную, независимо от \r\nсодержимого документа\r\n");
			// 
			// toolTip2
			// 
			this->toolTip2->ToolTipTitle = L"Автособираемое оглавление 2";
			// 
			// toolTip3
			// 
			this->toolTip3->ToolTipTitle = L"Ручное оглавление";
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->toolStripContainer6);
			this->panel6->Controls->Add(this->button6);
			this->panel6->Location = System::Drawing::Point(-1, 444);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(391, 98);
			this->panel6->TabIndex = 6;
			this->panel6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel6_Paint);
			// 
			// button6
			// 
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button6.Image")));
			this->button6->ImageAlign = System::Drawing::ContentAlignment::BottomLeft;
			this->button6->Location = System::Drawing::Point(1, 0);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(337, 23);
			this->button6->TabIndex = 7;
			this->button6->Text = L"Office.com ";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// toolTip4
			// 
			this->toolTip4->ToolTipTitle = L"Содержимое в сети недоступно";
			this->toolTip4->Popup += gcnew System::Windows::Forms::PopupEventHandler(this, &MyForm::toolTip4_Popup);
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::SystemColors::Window;
			this->button7->FlatAppearance->BorderColor = System::Drawing::SystemColors::MenuHighlight;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button7->FlatAppearance->MouseOverBackColor = System::Drawing::SystemColors::MenuHighlight;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button7->ForeColor = System::Drawing::Color::DimGray;
			this->button7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button7.Image")));
			this->button7->Location = System::Drawing::Point(-3, 0);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(393, 141);
			this->button7->TabIndex = 4;
			this->button7->Text = L"Автособираемое оглавление 2";
			this->button7->TextAlign = System::Drawing::ContentAlignment::TopLeft;
			this->toolTip2->SetToolTip(this->button7, L"Автоматически собираемое \r\nоглавление (с заголовком \r\n\"Оглавление\"), которое \r\nвк"
				L"лючает весь текст, \r\nоформленный стилями \r\n\"Заголовк 1-3\"\r\n");
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// toolStripContainer5
			// 
			this->toolStripContainer5->BottomToolStripPanelVisible = false;
			// 
			// toolStripContainer5.ContentPanel
			// 
			this->toolStripContainer5->ContentPanel->Controls->Add(this->statusStrip1);
			this->toolStripContainer5->ContentPanel->Size = System::Drawing::Size(150, 28);
			this->toolStripContainer5->LeftToolStripPanelVisible = false;
			this->toolStripContainer5->Location = System::Drawing::Point(390, 110);
			this->toolStripContainer5->Name = L"toolStripContainer5";
			this->toolStripContainer5->Size = System::Drawing::Size(150, 28);
			this->toolStripContainer5->TabIndex = 8;
			this->toolStripContainer5->Text = L"toolStripContainer5";
			this->toolStripContainer5->TopToolStripPanelVisible = false;
			// 
			// toolStripContainer6
			// 
			// 
			// toolStripContainer6.ContentPanel
			// 
			this->toolStripContainer6->ContentPanel->Size = System::Drawing::Size(146, 22);
			this->toolStripContainer6->Location = System::Drawing::Point(376, 0);
			this->toolStripContainer6->Name = L"toolStripContainer6";
			this->toolStripContainer6->Size = System::Drawing::Size(146, 22);
			this->toolStripContainer6->TabIndex = 8;
			this->toolStripContainer6->Text = L"Текст проверка текст";
			// 
			// statusStrip1
			// 
			this->statusStrip1->Dock = System::Windows::Forms::DockStyle::None;
			this->statusStrip1->Location = System::Drawing::Point(7, 5);
			this->statusStrip1->Name = L"statusStrip1";
			this->statusStrip1->Size = System::Drawing::Size(48, 22);
			this->statusStrip1->TabIndex = 0;
			this->statusStrip1->Text = L"текст";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Window;
			this->ClientSize = System::Drawing::Size(390, 541);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->flowLayoutPanel2);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"MyForm";
			this->Text = L"Оглавление";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->toolStripContainer1->ContentPanel->ResumeLayout(false);
			this->toolStripContainer1->ResumeLayout(false);
			this->toolStripContainer1->PerformLayout();
			this->toolStripContainer2->ContentPanel->ResumeLayout(false);
			this->toolStripContainer2->ResumeLayout(false);
			this->toolStripContainer2->PerformLayout();
			this->toolStripContainer3->ContentPanel->ResumeLayout(false);
			this->toolStripContainer3->ResumeLayout(false);
			this->toolStripContainer3->PerformLayout();
			this->toolStripContainer4->ResumeLayout(false);
			this->toolStripContainer4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel6->ResumeLayout(false);
			this->toolStripContainer5->ContentPanel->ResumeLayout(false);
			this->toolStripContainer5->ContentPanel->PerformLayout();
			this->toolStripContainer5->ResumeLayout(false);
			this->toolStripContainer5->PerformLayout();
			this->toolStripContainer6->ResumeLayout(false);
			this->toolStripContainer6->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {


}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolTip2_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
}
private: System::Void toolTip1_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
	panel2->ForeColor = System::Drawing::Color::Black;
	pictureBox1->ForeColor = System::Drawing::Color::Cyan;
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void toolTip4_Popup(System::Object^ sender, System::Windows::Forms::PopupEventArgs^ e) {
	button6->ForeColor = System::Drawing::Color::Black;
}
private: System::Void panel6_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
