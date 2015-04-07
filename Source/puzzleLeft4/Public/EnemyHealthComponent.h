#include "BaseHealthComponent.h"
#include "EnemyHealthComponent.generated.h"

/**
*
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PUZZLELEFT4_API UEnemyHealthComponent : public UBaseHealthComponent
{
	GENERATED_BODY()

public:
	UEnemyHealthComponent();
	virtual void InitializeComponent() override;
	virtual void OnDeath(FVector ForceDirection, float ForceValue) override;

};
