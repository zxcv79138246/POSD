#include "../cppunitlite/TestHarness.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <stack>

#include "Shape.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include "ShapeCalculate.h"
#include "ComboShape.h"
#include "Media.h"
#include "ShapeMedia.h"
#include "ComboMedia.h"
#include "AreaVisitor.h"
#include "PerimeterVisitor.h"
#include "DescriptionVisitor.h"
#include "MediaBuilder.h"
#include "ShapeMediaBuilder.h"
#include "ComboMediaBuilder.h"
#include "Text.h"
#include "TextMedia.h"
#include "TextVisitor.h"
#include "Document.h"
#include "MyDocument.h"
#include "MediaDirector.h"

#include "CommandManager.h"
#include "Command.h"
#include "addCommand.h"
#include "defCommand.h"
#include "deleteFromCommand.h"
#include "deleteAllCommand.h"

using namespace std;

TEST(CommandManagerExe, CommandManager) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    cmdMng->ExecuteCMD(defc);

    mapName["cSmall"]->accept(&dv);
    CHECK(string("c(2 1 1) ") == dv.getDescription())
}

TEST(CommandManagerUndo, CommandManager) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    cmdMng->ExecuteCMD(defc);
    cmdMng->UndoCMD();

    CHECK(mapName["cSmall"] == 0);
}

TEST(CommandManagerRedo, CommandManager) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    cmdMng->ExecuteCMD(defc);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();
    mapName["cSmall"]->accept(&dv);
    CHECK(string("c(2 1 1) ") == dv.getDescription())
}

TEST(defCommandExe, defCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    defc->Execute();

    mapName["cSmall"]->accept(&dv);
    CHECK(string("c(2 1 1) ") == dv.getDescription())
}

TEST(defCommandUndo, defCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    defc->Execute();
    defc->Undo();

    CHECK(mapName["cSmall"] == 0);
}

TEST(defCommandRedo, defCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    vector<string> sliceVector;
    sliceVector.push_back("def ");
    sliceVector.push_back("cSmall");
    sliceVector.push_back("Circle(2,1,1)");
    map<string, Media*> mapName;
    map<string, string> comboContent;
    defCommand* defc = new defCommand(sliceVector, &mapName, &comboContent);
    cmdMng->ExecuteCMD(defc);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();

    mapName["cSmall"]->accept(&dv);
    CHECK(string("c(2 1 1) ") == dv.getDescription());
}

TEST(addCommandExe, addCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("def");
    sliceVector4.push_back("cMale");
    sliceVector4.push_back("Circle(3,2,1)");
    vector<string> sliceVector5;
    sliceVector5.push_back("add");
    sliceVector5.push_back("cMale");
    sliceVector5.push_back("to");
    sliceVector5.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    defCommand* def4 = new defCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def4);
    addCommand* adc = new addCommand(sliceVector5, &mapName, &comboContent);
    adc->Execute();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(r(1 10 2 8) c(2 1 1) c(3 2 1) )") == dv.getDescription());
}

TEST(addCommandUndo, addCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("def");
    sliceVector4.push_back("cMale");
    sliceVector4.push_back("Circle(3,2,1)");
    vector<string> sliceVector5;
    sliceVector5.push_back("add");
    sliceVector5.push_back("cMale");
    sliceVector5.push_back("to");
    sliceVector5.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    defCommand* def4 = new defCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def4);
    addCommand* adc = new addCommand(sliceVector5, &mapName, &comboContent);
    adc->Execute();
    adc->Undo();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(r(1 10 2 8) c(2 1 1) )") == dv.getDescription());
}

TEST(addCommandRedo, addCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("def");
    sliceVector4.push_back("cMale");
    sliceVector4.push_back("Circle(3,2,1)");
    vector<string> sliceVector5;
    sliceVector5.push_back("add");
    sliceVector5.push_back("cMale");
    sliceVector5.push_back("to");
    sliceVector5.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    defCommand* def4 = new defCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def4);
    addCommand* adc = new addCommand(sliceVector5, &mapName, &comboContent);
    cmdMng->ExecuteCMD(adc);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(r(1 10 2 8) c(2 1 1) c(3 2 1) )") == dv.getDescription());
}

TEST(deleteFromCommandExe, deleteFromCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");
    sliceVector4.push_back("from");
    sliceVector4.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteFromCommand* dfc = new deleteFromCommand(sliceVector4, &mapName, &comboContent);
    dfc->Execute();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) )") == dv.getDescription());
}


TEST(deleteFromCommandUndo, deleteFromCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");
    sliceVector4.push_back("from");
    sliceVector4.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteFromCommand* dfc = new deleteFromCommand(sliceVector4, &mapName, &comboContent);
    dfc->Execute();
    dfc->Undo();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) r(1 10 2 8) )") == dv.getDescription());
}

TEST(deleteFromCommandRedo, deleteFromCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");
    sliceVector4.push_back("from");
    sliceVector4.push_back("comboExclamation");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteFromCommand* dfc = new deleteFromCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(dfc);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) )") == dv.getDescription());
}

TEST(deleteAllCommandExe1, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    dac->Execute();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) )") == dv.getDescription());
}

TEST(deleteAllCommandExe2, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    dac->Execute();

    CHECK(mapName["rTall"] == 0);
}

TEST(deleteAllCommandUndo1, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    dac->Execute();
    dac->Undo();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) r(1 10 2 8) )") == dv.getDescription());
}

TEST(deleteAllCommandUndo2, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    dac->Execute();
    dac->Undo();

    mapName["rTall"]->accept(&dv);
    CHECK(string("r(1 10 2 8) ") == dv.getDescription());
}

TEST(deleteAllCommandRedo1, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(dac);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();

    mapName["comboExclamation"]->accept(&dv);
    CHECK(string("combo(c(2 1 1) )") == dv.getDescription());
}

TEST(deleteAllCommandRedo2, deleteAllCommand) {
    DescriptionVisitor dv;
    CommandManager* cmdMng = new CommandManager();
    map<string, Media*> mapName;
    map<string, string> comboContent;

    vector<string> sliceVector1;
    sliceVector1.push_back("def");
    sliceVector1.push_back("cSmall");
    sliceVector1.push_back("Circle(2,1,1)");
    vector<string> sliceVector2;
    sliceVector2.push_back("def");
    sliceVector2.push_back("rTall");
    sliceVector2.push_back("Rectangle(1,10,2,8)");
    vector<string> sliceVector3;
    sliceVector3.push_back("def");
    sliceVector3.push_back("comboExclamation");
    sliceVector3.push_back("combo");
    sliceVector3.push_back("rTall,cSmall");
    vector<string> sliceVector4;
    sliceVector4.push_back("delete");
    sliceVector4.push_back("rTall");

    defCommand* def1 = new defCommand(sliceVector1, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def1);
    defCommand* def2 = new defCommand(sliceVector2, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def2);
    defCommand* def3 = new defCommand(sliceVector3, &mapName, &comboContent);
    cmdMng->ExecuteCMD(def3);
    deleteAllCommand* dac = new deleteAllCommand(sliceVector4, &mapName, &comboContent);
    cmdMng->ExecuteCMD(dac);
    cmdMng->UndoCMD();
    cmdMng->RedoCMD();

    CHECK(mapName["rTall"] == 0);
}
