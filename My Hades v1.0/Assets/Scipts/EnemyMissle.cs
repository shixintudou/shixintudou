using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemyMissle : MonoBehaviour
{
    public EnemyState state;
    private Rigidbody rigidbody;
    private float attacktime = 1.8f;
    private readonly float speed=40f;
    private HadesState hades;
    public bool isout = false;
    // Start is called before the first frame update
    void Start()
    {
        rigidbody = GetComponent<Rigidbody>();
        hades = FindObjectOfType<HadesState>();
    }

    // Update is called once per frame
    void Update()
    {
        if(state.HP>0)
        {
            if (Vector3.Distance(state.transform.position, hades.transform.position) < 29 && !isout)
            {
                isout = true;
                gameObject.layer = 0;
                transform.position = state.transform.position;
            }
            if (isout)
            {
                attacktime -= Time.deltaTime;
                if (attacktime < 0f)
                {
                    rigidbody.position = state.transform.position;
                    gameObject.layer = 2;
                    attacktime = 1.8f;
                    isout = false;
                }
            }
        }       
    }
    private void OnTriggerEnter(Collider other)
    {
        if (other.CompareTag("Player"))
        {
            hades.isattacked = true;
            hades.missled = true;
        }           
    }
    private void FixedUpdate()
    {
        if(isout&&state.HP>0)
        rigidbody.MovePosition(rigidbody.position + transform.forward * speed * Time.deltaTime);
    }
}
