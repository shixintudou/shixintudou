using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesAttack : MonoBehaviour
{
    public WeaponAction action;
    EnemyState[] enemy;
    // Start is called before the first frame update
    void Start()
    {
        enemy = FindObjectsOfType<EnemyState>();
    }

    // Update is called once per frame
    void Update()
    {
       
    }
    public void AttackJudge()
    {
        foreach(EnemyState i in enemy)
        {
            if(Vector3.Distance(transform.position,i.transform.position)<=25)
            {
                if(Vector3.Angle(transform.forward,i.transform.position-transform.position)<30)
                i.Behurt();
                i.HPdown(20);
            }
        }
    }
    public void SpecialAttackJudge()
    {
        foreach (EnemyState i in enemy)
        {
            if (Vector3.Distance(transform.position, i.transform.position) <= 30)
            {
                i.Behurt();
                i.HPdown(30);
            }
        }
    }
}
