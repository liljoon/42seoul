#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("Default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	target = other.target;
	this->AForm::operator=(other);

	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->checkExecute(executor);

	std::string file_name = this->target + "_shruberry";
	std::ofstream fout(file_name.c_str());
	fout << "              _{\\ _{\\{\\/}/}/}__\r\n             {/{/\\}{/{/\\}(\\}{/\\} _\r\n            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\r\n         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\r\n        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\r\n       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\r\n      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\r\n      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\r\n     {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}\r\n      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\r\n       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\r\n      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\r\n       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\r\n         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\r\n          (_){/{\\/}{\\{\\/}/}{\\{\\)/}/}(_)\r\n            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\r\n             {/{\\{\\{\\/}/}{\\{\\\\}/}\r\n              {){/ {\\/}{\\/} \\}\\}\r\n              (_)  \\.-\'.-/\r\n          __...--- |\'-.-\'| --...__\r\n   _...--\"   .-\'   |\'-.-\'|  \' -.  \"\"--..__\r\n -\"    \' .  . \'    |.\'-._| \'  . .  \'      \r\n .  \'-  \'    .--\'  | \'-.\'|    .  \'  . \'\r\n          \' ..     |\'-_.-|\r\n  .  \'  .       _.-|-._ -|-._  .  \'  .\r\n              .\'   |\'- .-|   \'.\r\n  ..-\'   \' .  \'.   `-._.-    .\'  \'  - .\r\n   .-\' \'        \'-._______.-\'     \'  .\r\n        .      ~," << std::endl;
	fout.close();
}
