#include "mainwindow.h"

MainWindow::MainWindow(QApplication* a_) {
    a=a_;
    score=0, lives=5;
    interval=0;  
    paused=false;  
    
    //Initialize unused pointers
    timer = NULL;
    player = NULL;
    pauseButton = NULL;
    resignButton = NULL;
    quitButton = NULL;
    
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    setScene(scene);
    
    //This sets the size of the window and gives it a title.
    setFixedSize( 1005, 505 );
    setWindowTitle( "Caterpillars");
    setFocusPolicy(Qt::StrongFocus);
    setFocus();
    
    mainMap = new QPixmap("images/main.png");
    canvas = new Canvas(0, 0, 1000, 500, 20, 0, 0, 0);
    canvas->setPixmap(*mainMap);
    scene->addItem(canvas);
    
    titleText = new QGraphicsSimpleTextItem("THE VERY HUNGRY\n     CATERPILLAR");
    titleText->setPos(220,100);
    titleText->setFont(QFont("Times New Roman", 40, QFont::Bold));
    titleText->setPen(QPen(Qt::white, 1, Qt::SolidLine));
    scene->addItem(titleText);
    
    subtitleText = new QGraphicsSimpleTextItem("A Qt game by Eric Pakravan, based on the story and artwork by Eric Carle");
    subtitleText->setPos(160,252);
    subtitleText->setFont(QFont("Ubuntu", 14, QFont::Bold));
    scene->addItem(subtitleText);
    
    scoreCaptionText = new QGraphicsSimpleTextItem("Score: ");
    scoreCaptionText->setPos(500,2);
    scoreCaptionText->setFont(QFont("Ubuntu", 15, QFont::Bold));
    scoreCaptionText->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    
    livesCaptionText = new QGraphicsSimpleTextItem("Lives: ");
    livesCaptionText->setPos(750,2);
    livesCaptionText->setFont(QFont("Ubuntu", 15, QFont::Bold));
    livesCaptionText->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    
    scoreText = new QGraphicsSimpleTextItem(QString::number(score));
    scoreText->setPos(565,2);
    scoreText->setFont(QFont("Ubuntu", 15, QFont::Bold));
    scoreText->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    
    livesText = new QGraphicsSimpleTextItem(QString::number(lives));
    livesText->setPos(810,2);
    livesText->setFont(QFont("Ubuntu", 15, QFont::Bold));
    livesText->setPen(QPen(Qt::red, 1, Qt::SolidLine));
    
    startButton = new QPushButton("Start!", this);
    startButton->setMinimumWidth(120);
    startButton->move(440, 280);
    startButton->setFont(QFont("Ubuntu", 20, QFont::Bold));
    connect(startButton, SIGNAL(clicked()), this, SLOT(StartGame()));
    startButton->show();
    
    backgroundMap = new QPixmap("images/background.png");
    caterpillarMap = new QPixmap("images/caterpillar.png");
  
    leafMap = new QPixmap("images/leaf.png");
    
    strawberryMap = new QPixmap("images/strawberry.png");
    orangeMap = new QPixmap("images/orange.png");
    plumMap = new QPixmap("images/plum.png");
    appleMap = new QPixmap("images/apple.png");
    pearMap = new QPixmap("images/pear.png");
    
    sunMap = new QPixmap("images/sun.png");
    
    ladybugMap = new QPixmap("images/ladybug.png");
    spiderMap = new QPixmap("images/spider.png");
    beeMap = new QPixmap("images/bee.png");

    cakeMap = new QPixmap("images/cake.png");
    pieMap = new QPixmap("images/pie.png");
    icecreamMap = new QPixmap("images/icecream.png");
    cupcakeMap = new QPixmap("images/cupcake.png");
    
}

void MainWindow::QuitGame() {
    a->quit();
}

void MainWindow::HandleTimer() {

    for (int i=0;i<itemAs.size();i++){
    	itemAs[i]->move();
    	if ((itemAs[i]->getX())<=0){
    		scene->removeItem(itemAs[i]);
    		delete itemAs.pop(i);
    	    	lives-=1;
    	 	livesText->setText(QString::number(lives));
    	 	if (lives==0) {
    	 		timer->stop();
    			break;
    	 	}
    	}
    }
    
    for (int i=0;i<itemBs.size();i++){
    	itemBs[i]->move();
    	if ((itemBs[i]->getY())>=500-itemBs[i]->getWidth()){
    		scene->removeItem(itemBs[i]);
    		delete itemBs.pop(i);
    	}	
    }
    
    for (int i=0;i<itemCs.size();i++){
    	itemCs[i]->onTimer();
    	for (int m=0;m<itemBs.size();m++){
    		if ((itemBs[m]->getBottom())>=itemCs[i]->getTop()&&
    		    (itemBs[m]->getRight())>=itemCs[i]->getLeft()&&
    		    (itemBs[m]->getLeft())<=itemCs[i]->getRight()){
    			scene->removeItem(itemBs[m]);
    			delete itemBs.pop(m);
    		}	
    	}
    	if ((itemCs[i]->getBottom()>=496)||
    	    (itemCs[i]->getRight()>=996)||
    	    (itemCs[i]->getX())<=4||
    	    (itemCs[i]->getY())<=24){
    		scene->removeItem(itemCs[i]);
    		delete itemCs.pop(i);
    	}	
    }
    for (int i=0;i<itemCs.size();i++){
	itemCs[i]->Top();
	itemCs[i]->Bottom();
	itemCs[i]->Left();
	itemCs[i]->Right();
    }
    
    for (int i=0;i<itemDs.size();i++){
    	int j=itemDs[i]->onTimer();
    	if ((j==2000)||
    	   ((player->getBottom()>=itemDs[i]->getTop())&&
    	    (player->getRight()>=itemDs[i]->getLeft())&&
    	    (player->getLeft()<=itemDs[i]->getRight())&&
    	    (player->getTop()<=itemDs[i]->getBottom()))){
    		scene->removeItem(itemDs[i]);
    		delete itemDs.pop(i);
    		score+=100;
    		scoreText->setText(QString::number(score));
    	}	
    }
    
    for (int i=0;i<itemEs.size();i++){
    	itemEs[i]->move();
    	if ((itemEs[i]->getX())<=0){
    		scene->removeItem(itemEs[i]);
    		delete itemEs.pop(i);
    	}
    }
    
    interval++;
    if ((interval%300)==20){
    	addFood();
    }
    
    if ((interval%200)==0){
    	addItemB();
    } 
    
    if ((interval%700)==100){
    	addItemC();
    } 
    
    if ((interval%900)==100){
    	addItemD();
    }
    
    if (lives==0) {
    	 timer->stop();
    	 GameOver();
    	 return;
    }
      
}


void MainWindow::StartGame(){
    score=0;
    lives=5;
    scoreText->setText(QString::number(score));
    livesText->setText(QString::number(lives));

    canvas->setPixmap(*backgroundMap);
    scene->removeItem(titleText);
    scene->removeItem(subtitleText);
    startButton->hide();

    player = new Player(canvas);
    player->setPixmap(*caterpillarMap);
    player->setData(&itemCs);
    scene->addItem(player);
    
    pauseButton = new QPushButton("Pause", this);
    pauseButton->move(2, 2);
    pauseButton->setFont(QFont("Ubuntu", 15, QFont::Bold));
    pauseButton->clearFocus();
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(PauseGame()));
    pauseButton->show();
    
    resignButton = new QPushButton("Resign", this);
    resignButton->move(100, 2);
    resignButton->setFont(QFont("Ubuntu", 15, QFont::Bold));
    resignButton->clearFocus();
    connect(resignButton, SIGNAL(clicked()), this, SLOT(GameOver()));
    resignButton->show();
    
    timer = new QTimer(this);
    timer->setInterval(10);
    connect(timer, SIGNAL(timeout()), this, SLOT(HandleTimer()));

    scene->addItem(scoreCaptionText);
    scene->addItem(livesCaptionText);    
    scene->addItem(scoreText);
    scene->addItem(livesText);
    
    timer->start();
}

void MainWindow::PauseGame(){
    pauseButton->clearFocus();
    if (!paused){	
	paused=true;
	timer->stop();
	pauseButton->setText("Resume");
    }
    else {
    	paused=false;
    	timer->start();
    	pauseButton->setText("Pause");
    }
}

void MainWindow::GameOver(){
    timer->stop();
    interval=0;
    lives=5;
    paused=false;

    canvas->setPixmap(*mainMap);
    scene->removeItem(scoreCaptionText);
    scene->removeItem(livesCaptionText);
    scene->removeItem(scoreText);
    scene->removeItem(livesText);
    startButton->show();

    scene->addItem(titleText);
    scene->addItem(subtitleText);

    scene->removeItem(player);
    delete player;
    delete pauseButton;
    delete resignButton;
    delete timer;
    
    itemAs.clear(scene);
    itemBs.clear(scene);
    itemCs.clear(scene);
    itemDs.clear(scene);
    itemEs.clear(scene);
}

void MainWindow::addFood(){
    switch (rand()%3){
    	case 0: addItemA(); break;
    	case 1: addItemA(); break;
    	case 2: addItemE(); break;
    }
}

void MainWindow::addItemA(){
    ItemA* itemA = new ItemA(canvas, player);
    
    switch (rand()%5){
    	case 0: itemA->setPixmap(*strawberryMap); break;
    	case 1: itemA->setPixmap(*orangeMap); break;
    	case 2: itemA->setPixmap(*appleMap); break;
    	case 3: itemA->setPixmap(*plumMap); break;
    	case 4: itemA->setPixmap(*pearMap); break;
    }
    itemAs.push_back(itemA);
    scene->addItem(itemA);
    
}

void MainWindow::addItemB(){
switch (rand()%3){  
    case 0:
    ItemB* itemB = new ItemB(canvas);
    itemB->setPixmap(*leafMap);
    itemBs.push_back(itemB);
    scene->addItem(itemB);
    break;
}
}

void MainWindow::addItemC(){    
switch (rand()%3){  
case 0:
    ItemC* itemC = new ItemC(canvas);
    switch (rand()%3){
    	case 0: itemC->setPixmap(*ladybugMap); break;
    	case 1: itemC->setPixmap(*spiderMap); break;
    	case 2: itemC->setPixmap(*beeMap); break;
    }
    	
    itemCs.push_back(itemC);
    itemC->setData(&itemCs);
    scene->addItem(itemC);
    break;
}   
}

void MainWindow::addItemD(){
switch (rand()%3){  
    case 0:
    ItemD* itemD = new ItemD(canvas);
    itemD->setPixmap(*sunMap);
    itemDs.push_back(itemD);
    itemD->setData(&itemCs);
    scene->addItem(itemD);
    break;
}   
}

void MainWindow::addItemE(){
    ItemE* itemE = new ItemE(canvas, player);
    switch (rand()%4){
    	case 0: itemE->setPixmap(*cakeMap); break;
    	case 1: itemE->setPixmap(*cupcakeMap); break;
    	case 2: itemE->setPixmap(*pieMap); break;
    	case 3: itemE->setPixmap(*icecreamMap); break;
    }
    itemEs.push_back(itemE);
    scene->addItem(itemE);
}

void MainWindow::eat(){
	player->eat();
	int AX = 0;
	for (int i=0;i<itemAs.size();i++){
		AX = (itemAs[i]->getX())-(player->getX());
		if (AX<50&&AX>0){
			score+=10;
    			scoreText->setText(QString::number(score));
    			scene->removeItem(itemAs[i]);
    			delete itemAs.pop(i);
		}
	}
}

void MainWindow::leaf(){

   if (itemBs.size()>0){
	int myY=player->getY();
	int myHeight=player->getHeight();
	int BY=(itemBs[0]->getY())+((itemBs[0]->getVelocityY())*30)+(itemBs[0]->getHeight()/2);
	int BX=(itemBs[0]->getX())+((itemBs[0]->getVelocityX())*30);
	
	if ((myY<=BY)&&(myY+myHeight>=BY)){
		player->leaf(BX);
		lives+=1;
		livesText->setText(QString::number(lives));
    		scene->removeItem(itemBs[0]);
    		delete itemBs.pop(0);
    	}
    	else {
    		player->eat();
    	}
   }
   else {
   	player->eat();
   }
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
   if(!paused){
	switch (e->key()){
	   case Qt::Key_Up:
		player->move_up();
		for (int i=0;i<itemAs.size();i++){
			itemAs[i]->move_up();
	   	}
		break;
	   case Qt::Key_Down:
		player->move_down();
		for (int i=0;i<itemAs.size();i++){
			itemAs[i]->move_down();
		}
		break;
	   case Qt::Key_Left:
		player->move_left();
		break;
	   case Qt::Key_Right:
		player->move_right();
		break;
	}
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent *e)
{
   if(!paused){
	switch (e->key()){
	   case Qt::Key_Return:
		leaf();
		break;
	   case Qt::Key_Space:
		eat();
		break;
	   case Qt::Key_P:
		PauseGame();
		break;
	}
    }
    else if (e->key()==Qt::Key_P)
    	PauseGame();
}

MainWindow::~MainWindow()
{
    if (timer) { timer->stop();
    delete timer; }
    
    //Buttons
    delete startButton;
    if (pauseButton) delete pauseButton;
    if (resignButton) delete resignButton;
    if (quitButton) delete quitButton;
    
    //QGraphics: SimpleTextItems
    delete titleText;
    delete subtitleText;
    delete scoreCaptionText;
    delete livesCaptionText;
    delete scoreText;
    delete livesText;
    
    //QGraphics: PixmapItems
    delete mainMap; delete backgroundMap; //Background Graphics
    delete caterpillarMap; //Player Graphics
    delete strawberryMap; delete orangeMap; delete plumMap; delete appleMap; delete pearMap; //ItemA Graphics
    delete leafMap; // ItemB Graphics
    delete ladybugMap; delete spiderMap; delete beeMap; //ItemC Graphics
    delete sunMap; //ItemD Graphics
    delete cakeMap; delete pieMap; delete icecreamMap; delete cupcakeMap; //ItemE Graphics
    
    //Data Arrays
    itemAs.clear(scene);
    itemBs.clear(scene);
    itemCs.clear(scene);
    itemDs.clear(scene);
    itemEs.clear(scene);
    
    //Window Items
    if (player) delete player;
    delete canvas;
    delete scene;
}

