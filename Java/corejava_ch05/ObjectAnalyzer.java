package learnjava.ch05;

import java.lang.reflect.*;
import java.util.ArrayList;

/**
* @version 1.0 2017/11/13
* @author WuJing GRT.
*/
public class ObjectAnalyzer
{
	private ArrayList<Object> visited = new ArrayList<>();

	/**
	* Concerts an Object to a string representation that lists all fields.
	* @param obj an object
	* @return a string with the object's class name and all field names and values
	*/
	public String toString(Object obj)
	{
		if(obj == null) return "null";
		if(visited.contains(obj)) return "...";
		visited.add(obj);
		Class cl = obj.getClass();
		if(cl == String.class) return (String) obj;
		if(cl.isArray())
		{
			String r = cl.getComponentType() + "[]{";
			for(int i = 0; i < Array.getLength(obj); i++)
			{
				if(i > 0) r += ",";
				//get value in obj iteratablelly
				Object val = Array.get(obj, i);
				if(cl.getComponentType().isPrimitive()) r += val;
				else r += toString(val);
			}
			return r + "}";
		}

		String r = cl.getName();
		//get field recursively
		do
		{
			r += "[";
			Field[] fields = cl.getDeclaredFields();
			//set the access authrity
			AccessibleObject.setAccessible(fields, true);
			for(Field f : fields)
			{
				if(!Modifier.isStatic(f.getModifiers()))
				{
					if(!r.endsWith("[")) r += ",";
					r += f.getName() + "=";
					try
					{
						//get the same class object
						Class t = f.getType();
						//get directive value
						//this will be autoboxing if it is primitive
						Object val = f.get(obj);
						if(t.isPrimitive()) r += val;
						else r += toString(val);
					}
					catch(Exception e)
					{
						e.printStackTrace();
					}
				}

			}

			r += "]";
			cl = cl.getSuperclass();
		}
		while(cl != null);

		return r;
	}
}