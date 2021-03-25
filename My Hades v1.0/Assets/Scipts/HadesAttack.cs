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
    public bool spearto=false;
    // Start is called before the first frame update
    void Start()
    {
        enemy = FindObjectsOfType<EnemyState>();
    }

    // Update is called once per frame
    void Update()
    {
        AttackJudge();
        SpecialAttackJudge();
    }
    public void AttackJudge()
    {
        switch (action.weaponnumber)
        {
            case 0:
                if (AnimationEvent.attackto)
                {
                    foreach (EnemyState i in enemy)
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
                break;
            case 1:
                if(Input.GetMouseButtonDown(0))
                {
                    foreach (EnemyState i in enemy)
                    {
                        if (Vector3.Distance(transform.position, i.transform.position) <= 35)
                        {
                            if (Vector3.Angle(transform.forward, i.transform.position - transform.position) < 20)
                            {
                                if (i == null)
                                    return;
                                i.beattacked = true;
                            }
                        }
                    }
                }
                break;
        }
        
    }
    public void SpecialAttackJudge()
    {
        switch (action.weaponnumber)
        {
            case 0:
                if (AnimationEvent.specialto)
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
                break;
            case 1:
                if(Input.GetKeyDown(KeyCode.Q))
                {
                    spearto = true;
                }
                if(spearto)
                {
                    foreach (EnemyState i in enemy)
                    {
                        if (Vector3.Distance(action.clone.transform.position, i.transform.position) <= 8.5f&&action.isspecial&&(!action.isout||!action.isback))
                        {
                            if (i == null)
                                return;
                            i.bespecialattacked = true;
                        }
                    }
                    if (action.isout == false &&
                    action.isspecial == false &&
                    action.isback == true)
                        spearto = false;
                }
                break;
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
