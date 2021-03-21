using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WeaponAction : MonoBehaviour
{
    Animation animation;
    private float attacktime = 0.2f;
    public GameObject Sword;
    public bool isattack = false;
    public bool isspecial = false;
    private float specialtime = 0.3f;
    // Start is called before the first frame update
    void Start()
    {
        animation = GetComponentInChildren<Animation>();
    }

    // Update is called once per frame
    void Update()
    {
        WeaponComeout();
        SpecialAttack();
    }

    private void WeaponComeout()
    {
        if(Input.GetMouseButtonDown(0) && !isspecial)
        {
            isattack = true;
        }
        if(isattack&&!isspecial)
        {
            animation.Play("Sword");
            attacktime -= Time.deltaTime;
            Sword.layer = 0;
            if (Mathf.Abs(attacktime)<=0.02f)
            {
                attacktime = 0.2f;
                isattack = false;
            }
        }
    }
    private void SpecialAttack()
    {
        if(Input.GetKeyDown(KeyCode.Q) && !isattack)
        {
            isspecial = true;
        }
        if(isspecial&&!isattack)
        {
            specialtime -= Time.deltaTime;
            if(Mathf.Abs(specialtime) <= 0.02f)
            {
                specialtime = 0.3f;
                isspecial = false;
            }
        }
    }
}
