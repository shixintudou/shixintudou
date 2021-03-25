using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimationEvent : MonoBehaviour
{
    public HadesAttack hades;
    public bool attackto ;
    public bool specialto ;
    public void HadesAttack()
    {
        attackto = true;
        specialto = true;
        hades.AttackJudge();
        hades.SpecialAttackJudge();
        attackto = false;
        specialto = false;
    }
}
