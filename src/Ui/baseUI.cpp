
#include "baseUI.h"

namespace Ui {

BaseUI::BaseUI(){}

BaseUI::~BaseUI(){}

System::MyTicSystem BaseUI::getSystem() const {
	return m_system;
}

}
