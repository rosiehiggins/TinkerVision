#pragma once

#include <QDockWidget>

#include "../../Core/SerializedObject.h"

class QScrollArea;
class QLabel; 
class QWidget;
class QVBoxLayout; 
class QHBoxLayout; 
class QListView;
class QPushButton; 
class QProcess; 
class QTextEdit; 

namespace TnkrVis
{

class SerializedObject; 

namespace GUI
{
    
namespace NodeEditor
{
class NodeEditorWidget; 
}

namespace ProjectHierarchy
{
	class ProjectHierarchyWidget; 
}

namespace BuildEditor
{
	
class BuildEditorWidget: public QDockWidget
{
	Q_OBJECT 
	
	private:
    	QScrollArea* scrollAreaBase;
		QWidget* widgetBase; 
		QVBoxLayout* layoutBase;

		QScrollArea* compileJsonTextScrollArea;
		QLabel*	compileJsonText; 
		QScrollArea* stdOutputTextScrollArea;
		QTextEdit* stdOutputText;
		QHBoxLayout* compileRunButtonLayout; 
		QPushButton* compileButton; 
		QPushButton* runButton; 

		NodeEditor::NodeEditorWidget* nodeEditorWidget; 
		ProjectHierarchy::ProjectHierarchyWidget* projectHierarchyWidget; 

		SerializedObject serializedComputeGraph; 

		QProcess* tinkerVisionProcess;

	public:
		BuildEditorWidget(NodeEditor::NodeEditorWidget* ne, ProjectHierarchy::ProjectHierarchyWidget* phw); 
};

}	
}
}
