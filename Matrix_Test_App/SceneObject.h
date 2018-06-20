#pragma once
#include <vector>
#include <Matrix3.h>

namespace aie
{
	class Renderer2D;
}

class SceneObject
{
public:
	SceneObject();
	virtual ~SceneObject();

	//returns the parents node 
	SceneObject* GetParent() const
	{
		return m_parent;
	}
	//counts how many children are in the collection
	size_t ChildCount() const
	{
		return m_children.size();
	}
	//returns the child from the collection
	SceneObject* GetChild(unsigned int index) const
	{
		return m_children[index];
	}
	//add child function
	void AddChild(SceneObject* child);
	//remove child function
	void RemoveChild(SceneObject* child);

	virtual void OnUpdate(float deltaTime) {};
	virtual void OnDraw(aie::Renderer2D* renderer) {};
	void Update(float deltaTime);
	void Draw(aie::Renderer2D * renderer);
	void UpdateTransform();

	//sets position of object
	void SetPosition(float x, float y);
	//sets rotate
	void SetRotate(float radians);
	//sets the scale
	void SetScale(float width, float height);
	//Translate: Translates the x and y cooridinates to a constant 
	void Translate(float x, float y);
	//rotates the object
	void Rotate(float radians);
	//scales the object
	void Scale(float width, float height);

	void SetLocal(Matrix3 transform);

	Matrix3& GetLocalTransform();
	Matrix3& GetGlobalTransform();


protected:
	//create a parent node which has no child yet
	SceneObject * m_parent = nullptr;
	//creating an array of children which are empty
	std::vector<SceneObject*> m_children;
	//we get the identity matrix from the maths lib and put it into the local transform
	Matrix3 m_localTransform = Matrix3::Identity();
	//we get the identity matrix from the maths lib and put it into the global transform
	Matrix3 m_globalTransform = Matrix3::Identity();
};

 