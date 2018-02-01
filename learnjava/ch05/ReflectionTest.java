package learnjava.ch05;

import java.lang.reflect.*;
import java.util.*;

/**
* This program demonstrates what reflection works.
* And it will print all features of a class.
* @version 1.0 2017-11-13
* @author WuJing GRT
*/
public class ReflectionTest
{
	// input class accroding dos.That is args[index]
	public static void main(String[] args)
	{
		String name;
		if(args.length > 0) name = args[0];
		else
		{
			Scanner in = new Scanner(System.in);
			System.out.println("Enter class name (e.g. java.util.Date): ");
			name = in.next();
		}

		try
		{
			ReflectionTest r = new ReflectionTest();
			Class classObject = Class.forName(name);
			//superclass where ot extends from.
			Class superClassObject = classObject.getSuperclass();

			String modifiers = Modifier.toString(classObject.getModifiers());
			if(modifiers.length() > 0)
				System.out.print(modifiers + " ");
			System.out.print("class " + name);
			// if superclass is not Object, print it.
			if(superClassObject != null && superClassObject != Object.class)
				System.out.print(" extends " + superClassObject.getName());
			System.out.print("\n{\n");


			r.printConstructors(classObject);
			System.out.println();
			r.printMethods(classObject);
			System.out.println();
			r.printFields(classObject);

			System.out.println("\n}");

		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
	}

	/**
	* get Class by method forName,
	* and then, we can do some operation on this class,
	* using java.lang.reflect.Filed,Method,Constructor and Modifier.
	* Orders:1.get modifiers. 2.get parameterTypes. 3.get name.
	*/
	public static void printConstructors(Class c1)
	{
		Constructor[] constructors = c1.getDeclaredConstructors();
		//All element of builders are null, we have to initialize them if used.
		StringBuilder[] builders = new StringBuilder[constructors.length];
		//index of StringBuilder arrays.
		int i = 0;
		for(Constructor c : constructors)
		{
			builders[i] = new StringBuilder();
			//create modifiers,and then create func name and parameters
			String modifiers = Modifier.toString(c.getModifiers());
			//space is inorder to set the form of String.
			if(modifiers.length() > 0)
				builders[i].append(modifiers + " ");
			String name = c.getName();
			builders[i].append(name);
			Class[] paramTypes = c.getParameterTypes();
			builders[i].append("(");
			for(Class temp : paramTypes)
			{
				//if parameters is the end one.
				if(temp != paramTypes[paramTypes.length - 1])
					builders[i].append(temp.getName() + ", ");
				else
					builders[i].append(temp.getName());
			}
			builders[i].append(");");

			// update
			i++;
		}

		System.out.println("Constructors:");
		for(StringBuilder sTemp : builders)
			System.out.println("	" + sTemp.toString());
	}

	/**
	* 1.modifiers. 2.return type. 3.name. 4.parameterTypes.
	*/
	public static void printMethods(Class c1)
	{
		Method[] methods = c1.getDeclaredMethods();
		StringBuilder[] builders = new StringBuilder[methods.length];
		int i = 0;
		for(Method m : methods)
		{
			//initialize builders.
			builders[i] = new StringBuilder();
			String modifiers = Modifier.toString(m.getModifiers());
			if(modifiers.length() > 0)
				builders[i].append(modifiers + " ");

			String returnType = m.getReturnType().getName();
			builders[i].append(returnType + " ");
			builders[i].append(m.getName() + "(");

			Class[] parameterTypes = m.getParameterTypes();
			for(Class c : parameterTypes)
			{
				if(c != parameterTypes[parameterTypes.length - 1])
					builders[i].append(c.getName() + ", ");
				else
					builders[i].append(c.getName());
			}
			builders[i].append(");");

			i++;
		}

		System.out.println("Methods:");
		for(StringBuilder s : builders)
			System.out.println("	" + s.toString());
	}

	public static void printFields(Class c1)
	{
		Field[] fields = c1.getDeclaredFields();
		//elements in builders have not been initialized.
		StringBuilder[] builders = new StringBuilder[fields.length];
		//index of builders
		int i = 0;
		for(Field f : fields)
		{
			//initialze builders.And get modifiers.
			builders[i] = new StringBuilder();
			String modifiers = Modifier.toString(f.getModifiers());
			if(modifiers.length() > 0)
				builders[i].append(modifiers + " ");
			//get type
			Class type = f.getType();
			String typeName = type.getName();
			if(typeName.length() > 0) 
				builders[i].append(typeName + " ");
			//get name.
			String name = f.getName();
			builders[i].append(name + ";");

			i++;
		}

		System.out.println("Fileds:");
		for(StringBuilder s : builders)
			System.out.println("	" + s.toString());

	}


}