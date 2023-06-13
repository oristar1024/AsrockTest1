#include "Head.h"
#include <conio.h>
#include "ConsoleEngineCore.h"

Head::Head() 
{
    SetChar('H');
    SetPos({ 0,0 });
}

Head::~Head() 
{
}

void Head::Tick(float _Time) 
{
    char Select = (char)_getch();

    int4 MovePos = { 0, 0 };

    switch (Select)
    {
    case 'a':
        MovePos = int4::Left;
        break;
    case 'd':
        MovePos = int4::Right;
        break;
    case 'w':
        MovePos = int4::Up;
        break;
    case 's':
        MovePos = int4::Down;
        break;
    case 'q':
        ConsoleEngineCore::EngineOff();
        break;
    default:
        break;
    }
    if (GetPos() + MovePos == PrevPos || ConsoleEngineCore::Screen.IsScreenOut(GetPos()+MovePos))
        return;

    std::list<Part*>::iterator Start = partList.begin();
    std::list<Part*>::iterator End = partList.end();
    for (; Start != End; ++Start)
    {
        Part* part = *Start;
        if (part->GetPos() == GetPos() + MovePos)
            return;
    }

    PrevPos = GetPos();
    AddPos(MovePos);

    Start = partList.begin();

    for (; Start != End; ++Start)
    {
        Part* part = *Start;
        part->Move();
    }


    
    if (body->GetPos() == GetPos()) 
    {
        AddPart();
        int4 Scale = ConsoleEngineCore::Screen.ScreenScale();
        int Bx = rand() % Scale.X;
        int By = rand() % Scale.Y;

        bool done = false;

        while (done == false)
        {
            done = true;
            Bx = rand() % Scale.X;
            By = rand() % Scale.Y;

            if (GetPos().X == Bx && GetPos().Y == By)
            {
                done = false;
                continue;
            }

            std::list<Part*>::iterator Start = partList.begin();
            std::list<Part*>::iterator End = partList.end();
            for (; Start != End; ++Start)
            {
                Part* part = *Start;
                if (part->GetPos().X == Bx && part->GetPos().Y == By)
                {
                    done = false;
                    break;
                }   
            }
        }

        body->SetPos({ Bx, By });
    }

}

Part* Head::AddPart()
{
    Part* tmp = ConsoleEngineCore::CreateObject<Part>();
    
    if (partList.size() == 0)
    {
        tmp->SetPrev(this);
    }

    else 
    {
        tmp->SetPrev(partList.back());
    }

    partList.push_back(tmp);

    return tmp;
}