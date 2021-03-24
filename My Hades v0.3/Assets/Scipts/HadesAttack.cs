using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesAttack : MonoBehaviour
{
    public WeaponAction action;
    EnemyState[] enemy;
    public HadesState hades;
    public AnimationEvent AnimationEvent;
    public MissleAttack missle;
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
        if (AnimationEvent.attackto)
        {
            foreach(EnemyState i in enemy)
            {
                if (Vector3.Distance(transform.position, i.transform.position) <= 25)
                {
                    if (Vector3.Angle(transform.forward, i.transform.position - transform.position) < 30)
                    {
                        if (i == null)
                            return;
                        i.beattacked = true;
                    }                                          
                }
            }
        }      
    }
    public void SpecialAttackJudge()
    {
        if(AnimationEvent.specialto)
        {
            foreach (EnemyState i in enemy)
            {
                if (Vector3.Distance(transform.position, i.transform.position) <= 30)
                {
                    if (i == null)
                        return;
                    i.bespecialattacked = true;
                }
            }
        }        
    }
    public void MissleJudge()
    {
        foreach(EnemyState i in enemy)
        {
            if(i.GetComponent<Collider>()==missle.collider)
            {
                if (i == null)
                    return;
                i.bemissled = true;
            }
        }
    }
}
