using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MissleAttack : MonoBehaviour
{
    public HadesAttack hades;
    private Rigidbody rigidbody;
    private readonly float speed = 50f;
    private float outtime = 10f;
    private bool isout = false;
    public Transform player;
    public Collider collider;
    // Start is called before the first frame update
    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetMouseButtonDown(1)&&!isout)
        {
            isout = true;
            rigidbody.transform.forward = player.forward;
        }
        if(isout)
        {
            gameObject.layer = 0;
            outtime -= Time.deltaTime;            
            if(outtime<=0)
            {
                rigidbody.position = hades.transform.position-new Vector3(0,3.29f,0);
                isout = false;
                outtime = 10f;
            }
        }
        if(!isout)
        {
            rigidbody.position = hades.transform.position - new Vector3(0, 2.29f, 0);
            gameObject.layer = 2;
        }
    }
    private void FixedUpdate()
    {
        if(isout)
            rigidbody.MovePosition( rigidbody.position+speed * transform.forward * Time.deltaTime);
    }
    private void OnTriggerEnter(Collider other)
    {
        if(isout)
        {
            collider = other;
            if (other.CompareTag("Shootable"))
            {
                hades.MissleJudge();
                isout = false;
                outtime = 10f;
            }
            if (other.CompareTag("Wall"))
            {
                rigidbody.position = hades.transform.position - new Vector3(0, 3.29f, 0);
                isout = false;
                outtime = 10f;
            }
        }       
    }

}
