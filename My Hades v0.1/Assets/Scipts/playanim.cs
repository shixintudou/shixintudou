using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playanim : MonoBehaviour
{
    // Start is called before the first frame update
    Animation anim;
    public string aname = "New Animation";
    private bool t = true;
    void Start()
    {
        anim = GetComponent<Animation>();
    }

    // Update is called once per frame
    private void Update()
    {
        
    }
    void OnMouseDown()
    {
        if (t)
        {
            anim[aname].speed = 1;
            anim.Play();
            t = false;
        }
        else
        {
            anim[aname].time = anim[aname].length;
            anim[aname].speed = -1;
            anim.Play();
            t = true;
        }
    }
}
