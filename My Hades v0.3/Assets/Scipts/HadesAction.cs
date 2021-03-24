using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HadesAction : MonoBehaviour
{
    public float speed;
    private int isright=0;
    private CharacterController controller;
    private float dashtime = 0.2f;
    private bool isdash = false;
   //public Transform allen;
    // Start is called before the first frame update
    void Start()
    {
        controller = GetComponent<CharacterController>();
    }
    // Update is called once per frame
    void Update()
    {
        PlayerMove();
        Dash();
    }

    private void PlayerMove()
    {
        float x = Input.GetAxisRaw("Horizontal");
        float y = Input.GetAxisRaw("Vertical");
        if (x != 0&&y==0)
        {
            controller.Move(new Vector3(x * speed * Time.deltaTime, 0, 0));
            if (x > 0 && isright != 1)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y-new Vector3(0,90,0).y)>=1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 1;
            }
            if (x < 0 && isright != -1)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 270, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = -1;
            }
        }
        if (y != 0&&x==0)
        {
            controller.Move(new Vector3(0, 0, y * speed * Time.deltaTime));
            if (y > 0 && isright != 0)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 0, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 0;
            }
            if (y < 0 && isright != -2)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 180, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = -2;
            }
        }
        if(x!=0&&y!=0)
        {
            controller.Move(new Vector3(x * speed * Time.deltaTime * Mathf.Sqrt(0.5f), 0, y * speed * Time.deltaTime * Mathf.Sqrt(0.5f)));
            if (x>0&&y>0&&isright!=2)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 45, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 2;
            }
            if (x < 0 && y > 0 && isright != 3)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 315, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 3;
            }
            if (x < 0 && y < 0 && isright != 4)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 225, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 4;
            }
            if (x > 0 && y < 0 && isright != 5)
            {
                if (Mathf.Abs(transform.rotation.eulerAngles.y - new Vector3(0, 135, 0).y) >= 1)
                    transform.Rotate(0, 45, 0, Space.World);
                else
                    isright = 5;
            }
        }
    }
    private void Dash()
    {
        if(Input.GetKeyDown(KeyCode.Space))
        {
            isdash = true;
        }
        if(isdash)
        {
            controller.Move(transform.forward * 2 * speed * Time.deltaTime);
            dashtime -= Time.deltaTime;
            if(Mathf.Abs(dashtime-0)<=0.05)
            {
                dashtime = 0.2f;
                isdash = false;               
            }
        }
    }
}